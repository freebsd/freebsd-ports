PORTNAME=	luv
DISTVERSION=	0.4.9.12
PORTREVISION=	2
CATEGORIES=	x11-themes gnome
PKGNAMEPREFIX=	gnome-icons-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Flat but complex icon theme for freedesktop environments

LICENSE=	CC-BY-SA-4.0
LICENSE_FILE=	${WRKSRC}/Luv/LICENSE

USES=		gnome
USE_GITHUB=	yes
GH_ACCOUNT=	NitruxSA
GH_PROJECT=	luv-icon-theme

DATADIR=	${PREFIX}/share/icons/Luv
INSTALLS_ICONS=	yes
NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@cd ${WRKSRC}/Luv && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
