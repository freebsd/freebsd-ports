# $FreeBSD$

PORTNAME=	xfs
PORTVERSION=	1.2.0
PORTEPOCH=	1
CATEGORIES=	x11-fonts

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org font server

XORG_CAT=	app
USES=		gmake
USE_XORG=	libfs xfont2 xtrans
USE_RC_SUBR=	xfs
CONFIGURE_ARGS=	--without-xmlto --without-fop

post-patch:
	${REINPLACE_CMD} '/^config_DATA/d' ${WRKSRC}/config/Makefile.in
.if defined(WITHOUT_XFS_CACHE)
	${REINPLACE_CMD} -e 's|^cache|XCOMM &|' ${WRKSRC}/config.cpp
.endif

post-build:
	@cd ${WRKSRC}/config/ && ${MAKE_CMD} config

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/X11/fs
	${INSTALL_SCRIPT} ${WRKSRC}/config/config \
		${STAGEDIR}${PREFIX}/etc/X11/fs/config.sample

.include <bsd.port.mk>
