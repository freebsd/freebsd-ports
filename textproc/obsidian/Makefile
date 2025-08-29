# This port will not be packaged by the official FreeBSD build cluster, because
# its license doesn't permit redistribution.
#
# To build this port locally with minimal effort use
# cd <PORTSDIR>/textproc/obsidian
# pkg install -A electron`make -V electronfix_ARGS`
# make USE_PACKAGE_DEPENDS_ONLY=yes install clean

PORTNAME=	obsidian
PORTVERSION=	1.9.10
PORTREVISION=	1
CATEGORIES=	textproc
# Icon is taken from the Nix build recipe
# https://github.com/NixOS/nixpkgs/blob/de5448dab588ad41aef40f8c7c0c230981656698/pkgs/applications/misc/obsidian/default.nix#L31-L34
MASTER_SITES=	https://github.com/obsidianmd/obsidian-releases/releases/download/v${PORTVERSION}/ \
		https://forum.obsidian.md/uploads/default/original/1X/:icon
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		bf119bd48f748f4fd2d65f2d1bb05d3c806883b5.png:icon
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Powerful and extensible knowledge base application
WWW=		https://obsidian.md

LICENSE=	EULA
LICENSE_NAME=	End User License Agreement
LICENSE_TEXT=	See https://obsidian.md/terms
LICENSE_PERMS=

USES=		electronfix:37

ELECTRONFIX_MAIN_EXECUTABLE=	obsidian
SUB_FILES=	obsidian
NO_BUILD=	yes

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/obsidian ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${PATCHDIR}/obsidian.desktop ${STAGEDIR}${DESKTOPDIR}/obsidian.desktop
	${INSTALL_DATA} ${DISTDIR}/bf119bd48f748f4fd2d65f2d1bb05d3c806883b5.png ${STAGEDIR}${PREFIX}/share/pixmaps/obsidian.png
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/metainfo
	${INSTALL_DATA} ${FILESDIR}/md.obsidian.obsidian.appdata.xml ${STAGEDIR}${PREFIX}/share/metainfo/

.include <bsd.port.mk>
