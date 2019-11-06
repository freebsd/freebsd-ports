# Created by: Andy Pavlo <amp0928@rit.edu>
# $FreeBSD$

PORTNAME=	hotkeys
PORTVERSION=	0.5.7.1
PORTREVISION=	18
CATEGORIES=	misc
MASTER_SITES=	https://BSDforge.com/projects/source/misc/hotkeys/${PORTVERSION}/
DISTNAME=	hotkeys_${PORTVERSION}

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Allows usage of special keys on internet/multimedia keyboards

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libxml2.so:textproc/libxml2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
CONFIGURE_ARGS=	--with-db3-inc=${BDB_INCLUDE_DIR} \
		--with-db3-lib=${BDB_LIB_DIR} \
		--with-db-name=${BDB_LIB_NAME}

USES=		bdb gmake xorg
USE_XORG=	x11 xft xkbfile xmu
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	OSD
OPTIONS_DEFAULT=	OSD

OSD_LIB_DEPENDS=	libxosd.so:misc/xosd
OSD_CONFIGURE_WITH=	xosd

post-extract:
	@${CP} ${PATCHDIR}/error.h ${WRKSRC}/src
	@${CP} ${PATCHDIR}/eliteduo.def ${WRKSRC}/def
	@${CP} ${PATCHDIR}/logitech-ultrax.def ${WRKSRC}/def

post-patch:
	@${REINPLACE_CMD} -e '/^install-exec-am/s/install-sysconfDATA//' \
		${WRKSRC}/src/Makefile.in
post-configure:
	${REINPLACE_CMD} -e 's,-lXinerama,-lXinerama `pkgconf --libs pangoxft`,g' ${WRKSRC}/src/Makefile

post-install:
	${INSTALL_DATA} ${WRKSRC}/src/hotkeys.conf ${STAGEDIR}${PREFIX}/etc/hotkeys.conf.sample

.include <bsd.port.mk>
