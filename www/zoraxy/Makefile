PORTNAME=	zoraxy
DISTVERSIONPREFIX=	v
DISTVERSION=	3.3.2
PORTREVISION=	2
CATEGORIES=	www

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	General purpose HTTP reverse proxy and forwarding tool
WWW=		https://github.com/tobychui/zoraxy

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC:H}/LICENSE

USES=		go:1.24+,modules
USE_GITHUB=	yes
GH_ACCOUNT=	tobychui
GH_PROJECT=	zoraxy

WRKSRC_SUBDIR=	src

GO_MODULE=	imuslab.com/zoraxy
GO_MOD_DIST=	github
GO_TARGET=	.

USERS=		zoraxy
GROUPS=		zoraxy

USE_RC_SUBR=	zoraxy
SUB_FILES=	pkg-message

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/zoraxy
	@${MKDIR} ${STAGEDIR}/var/db/zoraxy
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zoraxy/plugins
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zoraxy/www

.include <bsd.port.mk>
