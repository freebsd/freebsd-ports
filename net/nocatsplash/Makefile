# New ports collection makefile for:    NoCatSplash
# Date created:         19 November 2003
# Whom:                 Bruce M Simpson <bms@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nocatsplash
PORTVERSION=	0.82
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://nocat.net/download/NoCatSplash/
DISTNAME=	NoCatSplash-nightly
EXTRACT_SUFX=	.tgz

MAINTAINER=	bms@FreeBSD.org
COMMENT=	Open 802.11 Splash Screen

BUILD_DEPENDS= \
	${LOCALBASE}/sbin/pfctl:${PORTSDIR}/security/pf
RUN_DEPENDS= \
	${LOCALBASE}/sbin/pfctl:${PORTSDIR}/security/pf

USE_GNOME=	glib12

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		Requires 5.x or later for pf(4) firewall support
.endif

CONFLICTS=	nocatauth-server-*

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

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

.include <bsd.port.post.mk>
