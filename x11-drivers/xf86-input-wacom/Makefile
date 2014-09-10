# $FreeBSD$

PORTNAME=	xf86-input-wacom
PORTVERSION=	0.24.99.1
PORTREVISION=	1
CATEGORIES=	x11-drivers
MASTER_SITES=	SF/linuxwacom/${PORTNAME}

MAINTAINER=	jbeich@vfemail.net
COMMENT=	X.Org Wacom tablet driver

BUILD_DEPENDS=	v4l_compat>=1.0.20110603:${PORTSDIR}/multimedia/v4l_compat
RUN_DEPENDS=	webcamd>0:${PORTSDIR}/multimedia/webcamd

USES=		tar:bzip2 pathfix pkgconfig libtool
USE_XORG=	xrandr xinerama
XORG_CAT=	driver
SUB_FILES=	pkg-message
CONFIGURE_ARGS=	--without-systemd-unit-dir \
		--without-udev-rules-dir \
		--without-doxygen

post-patch:
	@${REINPLACE_CMD} -e 's/as_fn_error.*udev/${TRUE} &/' \
		-e 's/dir=.*xorg-server/& \
			--define-variable prefix="$$prefix"/' \
		${WRKSRC}/configure

# XXX adjust MatchProduct to whatever Xorg/devd reports
	@${REINPLACE_CMD} -e '/^SUBDIRS/s/ conf//' \
		${WRKSRC}/Makefile.in

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/xorg/modules/input/wacom_drv.so
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/X11/xorg.conf.d
	${INSTALL_DATA} ${FILESDIR}/wacom.conf.sample \
		${STAGEDIR}${PREFIX}/etc/X11/xorg.conf.d

.include <bsd.port.mk>
