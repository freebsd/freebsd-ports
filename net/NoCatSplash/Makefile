# New ports collection makefile for:    NoCatSplash
# Date created:         19 November 2003
# Whom:                 Bruce M Simpson <bms@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	NoCatSplash
PORTVERSION=	0.82
CATEGORIES=	net
MASTER_SITES=	http://nocat.net/download/${PORTNAME}/
DISTNAME=	${PORTNAME}-nightly
EXTRACT_SUFX=	.tgz

MAINTAINER=	bms@FreeBSD.org
COMMENT=	Open 802.11 Splash Screen

BUILD_DEPENDS= \
	${LOCALBASE}/sbin/pfctl:${PORTSDIR}/security/pf
RUN_DEPENDS= \
	${LOCALBASE}/sbin/pfctl:${PORTSDIR}/security/pf

#BROKEN=	Does not yet operate with the pf\(4\) firewall on FreeBSD

CONFLICTS=	NoCatAuth-Server-*

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	glib12

CONFIGURE_ARGS+=	--disable-dependency-tracking
CONFIGURE_ARGS+=	--disable-glibtest
CONFIGURE_ARGS+=	--with-firewall=pfctl
CONFIGURE_ARGS+=	--with-ghttpd
.if defined(AUTHMODE)
CONFIGURE_ARGS+=	--with-mode=${AUTHMODE}
.endif
.if defined(DOCROOT)
CONFIGURE_ARGS+=	--with-docroot=${DOCROOT}
.endif

.include <bsd.port.mk>
