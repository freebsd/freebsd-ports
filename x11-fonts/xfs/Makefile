# $FreeBSD$

PORTNAME=	xfs
PORTVERSION=	1.1.3
PORTEPOCH=	1
CATEGORIES=	x11-fonts

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org font server

XORG_CAT=	app
USE_GMAKE=	yes
USE_XORG=	libfs xfont xtrans
USE_RC_SUBR=	xfs
CONFIGURE_ARGS=	--without-xmlto --without-fop

MAN1=		xfs.1

NO_STAGE=	yes
post-patch:
	${REINPLACE_CMD} '/^config_DATA/d' ${WRKSRC}/config/Makefile.in
.if defined(WITHOUT_XFS_CACHE)
	${REINPLACE_CMD} -e 's|^cache|XCOMM &|' ${WRKSRC}/config.cpp
.endif

post-build:
	@cd ${WRKSRC}/config/ && ${GMAKE} config

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/config/config ${PREFIX}/etc/X11/fs/config.default
	@if [ ! -f ${PREFIX}/etc/X11/fs/config ]; then \
		${INSTALL_SCRIPT} ${WRKSRC}/config/config ${PREFIX}/etc/X11/fs/config; \
	fi

.include <bsd.port.mk>
