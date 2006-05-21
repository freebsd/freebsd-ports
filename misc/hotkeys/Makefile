# New ports collection makefile for:	hotkeys
# Date created:				May 20th, 2003
# Whom:					Andy Pavlo <amp0928@rit.edu>
#
# $FreeBSD$

PORTNAME=	hotkeys
PORTVERSION=	0.5.7.1
PORTREVISION=	3
CATEGORIES=	misc
MASTER_SITES=	http://ypwong.org/hotkeys/${PORTVERSION}/	\
		${MASTER_SITE_XCONTRIB}
DISTNAME=	hotkeys_${PORTVERSION}

MAINTAINER=	amp0928@rit.edu
COMMENT=	Allows usage of special keys on internet/multimedia keyboards

LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2 \
		db3.3:${PORTSDIR}/databases/db3

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
CONFIGURE_ARGS=	--with-db3-inc=${LOCALBASE}/include/db3 \
		--with-db3-lib=${LOCALBASE}/lib

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
MAN1=		hotkeys.1
ORIG_CONFIG=	${PREFIX}/etc/hotkeys.conf
SAMPLE_CONFIG=	${PREFIX}/etc/hotkeys.conf.sample

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

post-install:
	@${MV} ${ORIG_CONFIG} ${SAMPLE_CONFIG}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
