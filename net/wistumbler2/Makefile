# New ports collection makefile for:	wistumbler2
# Date created:		2003/11/15
# Whom:			Sebastian Yepes F. <esn@x123.info>
#
# $FreeBSD$
#

PORTNAME=	wistumbler2
PORTVERSION=	2.00
PORTREVISION=	5
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.nopcode.org/prj/wistumbler2/
DISTNAME=	wistumbler${PORTVERSION}-pre7

MAINTAINER=	esn@x123.info
COMMENT=	Network Stumbler for WaveLAN/IEEE Wireless

MAKE_ENV=	PREFIX=${LOCALBASE} USE_GTK=1
WRKSRC=		${WRKDIR}/${DISTNAME}

USE_GNOME=	gtk20

MANCOMPRESSED=	yes
MAN1=		wistumbler2.1
PLIST_FILES=	bin/wistumbler2

.if defined(NO_X)
MAKE_ENV=	PREFIX=${LOCALBASE} USE_GTK=0
.endif

.include <bsd.port.pre.mk>

# this port needs the file /sys/dev/owi/if_ieee80211.h, but there
# was not a FreeBSD version bump specifically for that.  Use the
# nearest one.
.if ${OSVERSION} < 501107
IGNORE=		requires never kernel sources that include /sys/dev/owi/if_ieee80211.h
.endif

pre-everything::
	@${ECHO} "You may specify the following on the command line:"
	@${ECHO} ""
	@${ECHO} " NO_X=yes  Disable The X(GTK2) Support."
	@${ECHO} ""

.include <bsd.port.post.mk>
