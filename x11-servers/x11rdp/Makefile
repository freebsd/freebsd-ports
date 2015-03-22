# Created by: Koichiro IWAO <meta+ports@vmeta.jp>
# $FreeBSD$

PORTNAME=	x11rdp
PORTVERSION=	0.5.0.${X11RDPREVISION}
PORTREVISION=	1
CATEGORIES=	x11-servers
MASTER_SITES=	http://www.club.kyutech.ac.jp/~meta/distfiles/:x11rdp
DISTNAME=	${PORTNAME}_xorg71
DISTFILES=	${PORTNAME}_xorg71_r${X11RDPREVISION}.tar.gz:x11rdp
DIST_SUBDIR=	xrdp

MAINTAINER=	meta+ports@vmeta.jp
COMMENT=	X11 server for xrdp

LICENSE=	MIT

RUN_DEPENDS=	xorg-fonts>=0:${PORTSDIR}/x11-fonts/xorg-fonts

# SVN revision of x11rdp
X11RDPREVISION=	299

USES=		gmake pkgconfig perl5
USE_OPENSSL=	yes
CONFLICTS_INSTALL=	xrdp-devel-[0-9]* x11rdp-devel-[0-9]*

PLIST_FILES=	bin/X11rdp

post-extract:
	@${MKDIR} ${WRKSRC}/build_dir

post-patch:
	@${REINPLACE_CMD} -e "s|%%LOCALBASE%%|${LOCALBASE}|g" ${WRKSRC}/buildx.sh
	@${REINPLACE_CMD} -e "s|%%CC%%|${CC}|g" ${WRKSRC}/buildx.sh
	@${REINPLACE_CMD} -e "s|%%CXX%%|${CXX}|g" ${WRKSRC}/buildx.sh
	@${REINPLACE_CMD} -e "s|%%CPP%%|${CPP}|g" ${WRKSRC}/buildx.sh
	@${REINPLACE_CMD} -e "s|%%MAKE_CMD%%|${MAKE_CMD}|g" ${WRKSRC}/buildx.sh

do-build:
	@cd ${WRKSRC} && GNUMAKE=${MAKE_CMD} ${SH} ${WRKSRC}/buildx.sh ${WRKSRC}/build_dir

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build_dir/bin/X11rdp ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
