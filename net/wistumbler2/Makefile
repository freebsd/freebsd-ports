# New ports collection makefile for:	wistumbler2
# Date created:		2003/11/15
# Whom:			Sebastian Yepes F. <esn@x123.info>
#
# $FreeBSD$
#

PORTNAME=	wistumbler2
PORTVERSION=	2.00
PORTREVISION=	11
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.nopcode.org/prj/wistumbler2/
DISTNAME=	wistumbler${PORTVERSION}-pre7

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Network Stumbler for WaveLAN/IEEE Wireless

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_GNOME=	gtk20

MANCOMPRESSED=	yes
MAN1=		wistumbler2.1
PLIST_FILES=	bin/wistumbler2

.if defined(NO_X)
MAKE_ENV=	USE_GTK=0
.else
MAKE_ENV=	USE_GTK=1
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 700045
IGNORE=		is not supported on FreeBSD 7.X and later
.endif

post-patch:
# Abovementioned header was removed.  Patch for it.
# This change is already included in the next version of wistumbler2
.if ${OSVERSION} >= 700006
	${REINPLACE_CMD} -e 's,dev/owi/if_ieee80211.h,net80211/ieee80211.h,g' \
		${WRKSRC}/src/stumbler.h
.endif

pre-everything::
	@${ECHO} "You may specify the following on the command line:"
	@${ECHO} ""
	@${ECHO} " NO_X=yes  Disable The X(GTK2) Support."
	@${ECHO} ""

.include <bsd.port.post.mk>
