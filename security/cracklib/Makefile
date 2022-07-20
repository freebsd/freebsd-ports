PORTNAME=	cracklib
PORTVERSION=	2.9.7
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	https://github.com/cracklib/cracklib/releases/download/v${PORTVERSION}/ \
		LOCAL/cy

DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${WORDS_DISTFILE}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	cy@FreeBSD.org
COMMENT?=	Password-checking library

LICENSE=	LGPL21

DICTPATH=	${PREFIX}/libdata/${PORTNAME}
DICTFILE=	${DICTPATH}/cracklib-words
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-default-dict=${DICTFILE}
INSTALL_TARGET=	install-strip
USES=		cpe libtool tar:bz2

CPE_VENDOR=	cracklib_project

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

.include <bsd.port.mk>
