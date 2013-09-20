# Created by: ajk@iu.edu
# $FreeBSD$

PORTNAME=	cracklib
PORTVERSION=	2.9.0
CATEGORIES=	security
.if defined(PYTHON_SLAVEPORT)
CATEGORIES+=	python
.endif
MASTER_SITES=	SF \
		LOCAL/${MAINTAINER:C/([^@]*)@.*/\1/}

MAINTAINER=	sbz@FreeBSD.org
COMMENT?=	Password-checking library

LICENSE=	LGPL21

DICTPATH=	${PREFIX}/libdata/${PORTNAME}
DICTFILE=	${DICTPATH}/pw_dict
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=--with-default-dict=${DICTPATH}
USE_LDCONFIG=	yes

.if defined(PYTHON_SLAVEPORT)
USE_PYTHON=	yes
CONFIGURE_ARGS+=--with-python
PLIST_FILES=	%%PYTHON_SITELIBDIR%%/_cracklib.a \
		%%PYTHON_SITELIBDIR%%/_cracklib.la \
		%%PYTHON_SITELIBDIR%%/_cracklib.so \
		%%PYTHON_SITELIBDIR%%/cracklib.py \
		%%PYTHON_SITELIBDIR%%/cracklib.pyc \
		%%PYTHON_SITELIBDIR%%/cracklib.pyo \
		%%PYTHON_SITELIBDIR%%/test_cracklib.py \
		%%PYTHON_SITELIBDIR%%/test_cracklib.pyc \
		%%PYTHON_SITELIBDIR%%/test_cracklib.pyo
.else
CONFIGURE_ARGS+=--without-python
PLIST_DIRS=	libdata/cracklib \
		share/cracklib

PLIST_FILES=	include/crack.h \
		include/packer.h \
		lib/libcrack.a \
		lib/libcrack.la \
		lib/libcrack.so \
		lib/libcrack.so.11 \
		libdata/cracklib/pw_dict.hwm \
		libdata/cracklib/pw_dict.pwd \
		libdata/cracklib/pw_dict.pwi \
		sbin/cracklib-check \
		sbin/cracklib-format \
		sbin/cracklib-packer \
		sbin/cracklib-unpacker \
		sbin/create-cracklib-dict \
		%%DATADIR%%/cracklib-small \
		%%DATADIR%%/cracklib.magic
.endif

.if defined(PYTHON_SLAVEPORT)
NO_STAGE=	yes
pre-build:
	cd ${WRKSRC}/lib && ${MAKE} libcrack.la

regression-test: extract
	@(cd ${BUILD_WKRSRC}; \
	${PYTHON_CMD} -c \
	"from test_${PORTNAME} import run; run(use_dictpath=\"${DICTFILE}\")")
.else
MAN3=		${PORTNAME}.3
MLINKS=		${PORTNAME}.3 FascistCheck.3

post-install:
	${INSTALL_MAN} ${FILESDIR}/${MAN3} ${MAN3PREFIX}/man/man3/
	@${MKDIR} ${DICTPATH}
	${INSTALL_DATA} ${FILESDIR}/pw_dict* ${DICTPATH}/
.endif

.include <bsd.port.mk>
