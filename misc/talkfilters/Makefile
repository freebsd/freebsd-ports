PORTNAME=	talkfilters
DISTVERSION=	2.3.8
PORTREVISION=	3
CATEGORIES=	misc
MASTER_SITES=	http://www.hyperrealm.com/talkfilters/ \
		LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Set of filters to convert English text to various stereotyped dialects
WWW=		https://www.hyperrealm.com/talkfilters/talkfilters.html

LICENSE=	GPLv2

USES=		libtool pathfix
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFLICTS=	chef filters

SUB_FILES=	pkg-message

INFO=		talkfilters

post-extract:
	@${ECHO} ${DO_NADA} > ${WRKSRC}/install-sh
	@${CHMOD} +x ${WRKSRC}/install-sh

post-patch:
	@${RM} ${WRKSRC}/*.info*

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libtalkfilters.so*

.include <bsd.port.mk>
