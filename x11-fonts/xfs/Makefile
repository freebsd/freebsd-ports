PORTNAME=	xfs
DISTVERSION=	1.2.2
PORTEPOCH=	1
CATEGORIES=	x11-fonts

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org font server
WWW=		https://gitlab.freedesktop.org/xorg/app/xfs

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe gmake tar:xz xorg xorg-cat:app
CPE_VENDOR=	x.org
CPE_PRODUCT=	x_font_server
USE_XORG=	xfont2 xorgproto xtrans
USE_RC_SUBR=	xfs
CONFIGURE_ARGS=	--without-xmlto --without-fop

post-patch:
	${REINPLACE_CMD} '/^config_DATA/d' ${WRKSRC}/config/Makefile.in

post-build:
	@cd ${WRKSRC}/config/ && ${MAKE_CMD} config

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/X11/fs
	${INSTALL_SCRIPT} ${WRKSRC}/config/config \
		${STAGEDIR}${PREFIX}/etc/X11/fs/config.sample

.include <bsd.port.mk>
