# Created by: Koichiro IWAO <meta+ports@vmeta.jp>
# $FreeBSD$

# Do not confuse net/xrdp with x11-servers/x11rdp.  This port is not
# former version or name of net/xrdp. x11rdp is fundamentally an X server.
# xrdp is a RDP server.  They work together.  Neither xrdp nor x11rdp
# can be used fully functionally without the other.
#
# Simply saying, net/xrdp is front-end, x11-servers/x11rdp is back-end.

PORTNAME=	x11rdp
PORTVERSION=	0.5.0.${X11RDPREVISION}
PORTREVISION=	1
CATEGORIES=	x11-servers
MASTER_SITES=	https://xrdp.vmeta.jp/pub/xrdp/:x11rdp \
		http://www.club.kyutech.ac.jp/~meta/distfiles/:x11rdp
DISTNAME=	${PORTNAME}_xorg71
DISTFILES=	${PORTNAME}_xorg71_r${X11RDPREVISION}.tar.gz:x11rdp
DIST_SUBDIR=	xrdp

MAINTAINER=	meta+ports@vmeta.jp
COMMENT=	X11 server for xrdp

LICENSE=	MIT

BROKEN_powerpc64=	Does not build

RUN_DEPENDS=	xorg-fonts>=0:x11-fonts/xorg-fonts

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
