# New ports collection makefile for: 	nessus
# Date created:		1 May 1999
# Whom:			Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	nessus
PORTVERSION=	1.0.7
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.cis.fed.gov/pub/nessus/nessus-${PORTVERSION}/ \
		ftp://ftp.nessus.org/pub/nessus/nessus-${PORTVERSION}/ \
		ftp://cvs.nessus.org/pub/nessus/nessus-${PORTVERSION}/ \
		ftp://ftp.gwdg.de/pub/linux/misc/nessus/nessus-${PORTVERSION}/ \
		http://ftp.gwdg.de/pub/linux/misc/nessus/nessus-${PORTVERSION}/ \
		ftp://ftp.esiea.fr/pub/mirrors/nessus/nessus-${PORTVERSION}/ \
		ftp://sunsite.cnlab-switch.ch/mirror/nessus/nessus-${PORTVERSION}/ \
		ftp://ftp.chg.ru/pub/security/nessus/nessus-${PORTVERSION}/ \
		ftp://ftp.sekure.net/pub/nessus/nessus-${PORTVERSION}/
DISTNAME=	nessus-core-${PORTVERSION}

MAINTAINER=	olgeni@FreeBSD.org

LIB_DEPENDS=	nasl.1:${PORTSDIR}/security/nessus-libnasl

DIST_SUBDIR=	nessus
WRKSRC=		${WRKDIR}/nessus-core

HAVE_GTK=	yes
USE_LIBTOOL=	yes
.if defined(WITHOUT_GTK)
CONFIGURE_ARGS+=	--disable-gtk
.endif

MAN1=		nessus.1
MAN8=		nessusd.8 nessus-adduser.8

post-install:
	@${ECHO} "================================================================================"
	@${ECHO} "Use ${PREFIX}/sbin/update/nessus-update-plugins to update your plugin"
	@${ECHO} "collection."
	@${ECHO} "================================================================================"

.include <bsd.port.mk>
