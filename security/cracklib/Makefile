# Created by: ajk@iu.edu
# $FreeBSD$

PORTNAME=	cracklib
PORTVERSION=	2.9.0
PORTREVISION=	1
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
CONFIGURE_ARGS=	--with-default-dict=${DICTPATH}
INSTALL_TARGET=	install-strip
USES=		gettext libtool
USE_LDCONFIG=	yes

.if defined(PYTHON_SLAVEPORT)
USES+=		python
CONFIGURE_ARGS+=--with-python
PLIST_FILES=	%%PYTHON_SITELIBDIR%%/_cracklib.a \
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
		share/cracklib \
		share/locale/as/LC_MESSAGES \
		share/locale/as \
		share/locale/bn_IN/LC_MESSAGES \
		share/locale/bn_IN \
		share/locale/mr/LC_MESSAGES \
		share/locale/mr \
		share/locale/sl_SI/LC_MESSAGES \
		share/locale/sl_SI \
		share/locale/te/LC_MESSAGES \
		share/locale/te

PLIST_FILES=	include/crack.h \
		include/packer.h \
		lib/libcrack.a \
		lib/libcrack.so \
		lib/libcrack.so.2 \
		lib/libcrack.so.2.9.0 \
		libdata/cracklib/pw_dict.hwm \
		libdata/cracklib/pw_dict.pwd \
		libdata/cracklib/pw_dict.pwi \
		man/man3/FascistCheck.3.gz \
		man/man3/cracklib.3.gz \
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
	cd ${WRKSRC}/lib && ${MAKE_CMD} libcrack.la

regression-test: extract
	@(cd ${BUILD_WKRSRC}; \
	${PYTHON_CMD} -c \
	"from test_${PORTNAME} import run; run(use_dictpath=\"${DICTFILE}\")")
.else
post-install:
	${INSTALL_MAN} ${FILESDIR}/${PORTNAME}.3 ${STAGEDIR}${MAN3PREFIX}/man/man3/
	${LN} -s ${PORTNAME}.3 ${STAGEDIR}${MAN3PREFIX}/man/man3/FascistCheck.3
	@${MKDIR} ${STAGEDIR}${DICTPATH}
	${INSTALL_DATA} ${FILESDIR}/pw_dict* ${STAGEDIR}${DICTPATH}/
.endif

.include <bsd.port.mk>
