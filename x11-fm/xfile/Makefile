PORTNAME=	xfile
DISTVERSIONPREFIX=	src-
DISTVERSION=	1.0
DISTVERSIONSUFFIX=	-beta
CATEGORIES=	x11-fm
MASTER_SITES=	https://fastestcode.org/dl/

MAINTAINER=	corlat@ermaion.com
COMMENT=	File manager for Unix and alike systems running X11
WWW=		https://fastestcode.org/xfile.html

LICENSE=	MIT

USES=		motif tar:xz
USE_XORG=	x11 xinerama xt

# The mkicons.sh script makes MAKE_JOBS_UNSAFE necessary.
# Could be circumvnented by executing the script before building.
MAKE_JOBS_UNSAFE=	yes

# Workaround necessary until upstream change the name of the source archive;
# probably not until next release.
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}-rc2

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@(cd ${STAGEDIR}${PREFIX}/bin && ${LN} -s ${PORTNAME} ${PORTNAME}-open)
	${MKDIR} ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_MAN} ${WRKSRC}/src/${PORTNAME}.1 \
		${STAGEDIR}${PREFIX}/share/man/man1
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/X11/app-defaults
	${INSTALL_DATA} ${WRKSRC}/src/${PORTNAME}.ad \
		${STAGEDIR}${PREFIX}/etc/X11/app-defaults/Xfile
	${MKDIR} ${STAGEDIR}${PREFIX}/share/xfile/types
	${INSTALL_DATA} ${WRKSRC}/src/default.db \
		${STAGEDIR}${PREFIX}/share/xfile/types/system.db
	${MKDIR} ${STAGEDIR}${PREFIX}/share/xfile/icons
	${INSTALL_DATA} ${WRKSRC}/src/icons/*.xpm \
		${STAGEDIR}${PREFIX}/share/xfile/icons
	${INSTALL_DATA} ${WRKSRC}/src/icons/README \
		${STAGEDIR}${PREFIX}/share/xfile/README.icons
	${MKDIR} ${STAGEDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/src/xbm/cabinet.xpm \
		${STAGEDIR}${PREFIX}/share/pixmaps/xfile_48x48.xpm

.include <bsd.port.mk>
