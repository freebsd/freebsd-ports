PORTNAME=	monaspace
DISTVERSION=	1.400
PORTREVISION=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/githubnext/${PORTNAME}/releases/download/v${DISTVERSION}/
DISTFILES=	${PORTNAME}-static-v${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-variable-v${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Innovative superfamily of fonts for code
WWW=		https://monaspace.githubnext.com

LICENSE=	OFL11

USES=		fonts

EXTRACT_SUFX=	.zip
EXTRACT_AFTER_ARGS=	--strip-components 2 \
			--no-same-owner --no-same-permissions

NO_WRKSUBDIR=	yes
NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/* ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
