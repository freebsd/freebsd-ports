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

MAINTAINER= 	cy@FreeBSD.org
COMMENT?=	Password-checking library

LICENSE=	LGPL21

DICTPATH=	${PREFIX}/libdata/${PORTNAME}
DICTFILE=	${DICTPATH}/pw_dict
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=--with-default-dict=${DICTPATH}
USE_LDCONFIG=	yes
USES=		gettext

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
		%%DATADIR%%/cracklib.magic \
		share/locale/as/LC_MESSAGES/cracklib.mo \
		share/locale/bn_IN/LC_MESSAGES/cracklib.mo \
		share/locale/cs/LC_MESSAGES/cracklib.mo \
		share/locale/da/LC_MESSAGES/cracklib.mo \
		share/locale/de/LC_MESSAGES/cracklib.mo \
		share/locale/el/LC_MESSAGES/cracklib.mo \
		share/locale/es/LC_MESSAGES/cracklib.mo \
		share/locale/fi/LC_MESSAGES/cracklib.mo \
		share/locale/fr/LC_MESSAGES/cracklib.mo \
		share/locale/gu/LC_MESSAGES/cracklib.mo \
		share/locale/hi/LC_MESSAGES/cracklib.mo \
		share/locale/hu/LC_MESSAGES/cracklib.mo \
		share/locale/it/LC_MESSAGES/cracklib.mo \
		share/locale/ja/LC_MESSAGES/cracklib.mo \
		share/locale/kn/LC_MESSAGES/cracklib.mo \
		share/locale/ko/LC_MESSAGES/cracklib.mo \
		share/locale/lt/LC_MESSAGES/cracklib.mo \
		share/locale/ml/LC_MESSAGES/cracklib.mo \
		share/locale/mr/LC_MESSAGES/cracklib.mo \
		share/locale/nb/LC_MESSAGES/cracklib.mo \
		share/locale/nl/LC_MESSAGES/cracklib.mo \
		share/locale/or/LC_MESSAGES/cracklib.mo \
		share/locale/pa/LC_MESSAGES/cracklib.mo \
		share/locale/pl/LC_MESSAGES/cracklib.mo \
		share/locale/pt/LC_MESSAGES/cracklib.mo \
		share/locale/pt_BR/LC_MESSAGES/cracklib.mo \
		share/locale/ru/LC_MESSAGES/cracklib.mo \
		share/locale/sk/LC_MESSAGES/cracklib.mo \
		share/locale/sl_SI/LC_MESSAGES/cracklib.mo \
		share/locale/ta/LC_MESSAGES/cracklib.mo \
		share/locale/te/LC_MESSAGES/cracklib.mo \
		share/locale/tr/LC_MESSAGES/cracklib.mo \
		share/locale/uk/LC_MESSAGES/cracklib.mo \
		share/locale/zh_CN/LC_MESSAGES/cracklib.mo \
		share/locale/zh_TW/LC_MESSAGES/cracklib.mo
.endif

.if defined(PYTHON_SLAVEPORT)
pre-build:
	cd ${WRKSRC}/lib && ${MAKE} libcrack.la

regression-test: extract
	@(cd ${BUILD_WKRSRC}; \
	${PYTHON_CMD} -c \
	"from test_${PORTNAME} import run; run(use_dictpath=\"${DICTFILE}\")")
.else
PLIST_FILES+=	man/man3/${PORTNAME}.3.gz \
		@exec\ ln\ -s\ man/man3/${PORTNAME}.3.gz\ man/man3/FascistCheck.3.gz \
		@unexec\ rm\ man/man3/FascistCheck.3.gz

post-install:
	${INSTALL_MAN} ${FILESDIR}/${PORTNAME}.3 ${STAGEDIR}${MAN3PREFIX}/man/man3/
	@${MKDIR} ${STAGEDIR}${DICTPATH}
	${INSTALL_DATA} ${FILESDIR}/pw_dict* ${STAGEDIR}${DICTPATH}/
.endif

.include <bsd.port.mk>
