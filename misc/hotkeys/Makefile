# New ports collection makefile for:	hotkeys
# Date created:				May 20th, 2003
# Whom:					Andy Pavlo <amp0928@rit.edu>
#
# $FreeBSD$

PORTNAME=	hotkeys
PORTVERSION=	0.5.7.1
PORTREVISION=	9
CATEGORIES=	misc
MASTER_SITES=	http://ypwong.org/hotkeys/${PORTVERSION}/	\
		${MASTER_SITE_XCONTRIB}
DISTNAME=	hotkeys_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Allows usage of special keys on internet/multimedia keyboards

LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
CONFIGURE_ARGS=	--with-db3-inc=${BDB_INCLUDE_DIR} \
		--with-db3-lib=${BDB_LIB_DIR} \
		--with-db-name=${BDB_LIB_NAME}

USE_XORG=	x11 xkbfile xmu
GNU_CONFIGURE=	yes
USE_BDB=	yes
USE_GMAKE=	yes

MAN1=		hotkeys.1

OPTIONS=	XOSD	"Enable On-Screen-Display support"	on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_XOSD)
LIB_DEPENDS+=	xosd.4:${PORTSDIR}/misc/xosd
CONFIGURE_ARGS+=	--with-xosd
.endif

post-extract:
	@${CP} ${PATCHDIR}/error.h ${WRKSRC}/src
	@${CP} ${PATCHDIR}/eliteduo.def ${WRKSRC}/def
	@${CP} ${PATCHDIR}/logitech-ultrax.def ${WRKSRC}/def

post-patch:
	@${REINPLACE_CMD} -e '/^install-exec-am/s/install-sysconfDATA//' \
		${WRKSRC}/src/Makefile.in

post-install:
	@${INSTALL_DATA} ${WRKSRC}/src/hotkeys.conf ${PREFIX}/etc/hotkeys.conf.sample
	@if [ ! -f ${PREFIX}/etc/hotkeys.conf ]; then \
	  ${CP} -p ${PREFIX}/etc/hotkeys.conf.sample ${PREFIX}/etc/hotkeys.conf ; \
	fi
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
