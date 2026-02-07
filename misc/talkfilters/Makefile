PORTNAME=	talkfilters
DISTVERSION=	2.4
CATEGORIES=	misc
MASTER_SITES=	https://hyperrealm.github.io/talkfilters/dist/ \
		LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Set of filters to convert English text to various stereotyped dialects
WWW=		https://hyperrealm.github.io/talkfilters/ \
		https://github.com/hyperrealm/talkfilters

LICENSE=	GPLv2

USES=		libtool pathfix
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFLICTS=	chef filters

SUB_FILES=	pkg-message

INFO=		talkfilters

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libtalkfilters.so*

.include <bsd.port.mk>
