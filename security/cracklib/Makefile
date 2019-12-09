# Created by: ajk@iu.edu
# $FreeBSD$

PORTNAME=	cracklib
PORTVERSION=	2.9.7
CATEGORIES=	security
MASTER_SITES=	https://github.com/cracklib/cracklib/releases/download/v${PORTVERSION}/ \
		LOCAL/cy
.if !defined(PYTHON_SLAVEPORT)
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
		${WORDS_DISTFILE}
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}
.endif

MAINTAINER=	cy@FreeBSD.org
COMMENT?=	Password-checking library

LICENSE=	LGPL21

DICTPATH=	${PREFIX}/libdata/${PORTNAME}
DICTFILE=	${DICTPATH}/cracklib-words
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-default-dict=${DICTFILE}
INSTALL_TARGET=	install-strip
USES=		libtool tar:bz2

.if defined(PYTHON_SLAVEPORT)
CATEGORIES+=	python

USES+=		python:2.7 localbase
USE_PYTHON=	flavors

CONFIGURE_ARGS+=--disable-nls --with-python

pre-build:
	cd ${WRKSRC}/lib && ${MAKE_CMD} libcrack.la

do-test:
	@(cd ${BUILD_WKRSRC} && ${SETENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} \
		${PYTHON_CMD} -c \
		"from test_${PORTNAME} import run; run(use_dictpath=\"${DICTFILE:S|^${PREFIX}/|${LOCALBASE}/|}\")")
.else
WORDS_DISTFILE=	${PORTNAME}-words-${PORTVERSION}.bz2

USE_LDCONFIG=	yes

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	NLS

NLS_CONFIGURE_OFF=--disable-nls
NLS_USES=	gettext

CONFIGURE_ARGS+=--without-python

post-install:
	${INSTALL_MAN} ${FILESDIR}/${PORTNAME}.3 ${STAGEDIR}${MAN3PREFIX}/man/man3/
	${LN} -s ${PORTNAME}.3 ${STAGEDIR}${MAN3PREFIX}/man/man3/FascistCheck.3
	@${MKDIR} ${STAGEDIR}${DICTPATH}
	@PATH=$${PATH}:${STAGEDIR}${PREFIX}/sbin LD_LIBRARY_PATH=/lib:/usr/lib:${STAGEDIR}${PREFIX}/lib ${STAGEDIR}${PREFIX}/sbin/create-cracklib-dict -o ${STAGEDIR}${DICTPATH}/cracklib-words ${_DISTDIR}/${WORDS_DISTFILE}
.endif

.include <bsd.port.mk>
