# Ports collection makefile for:	nessus-plugins
# Date created:				16 October 1999
# Whom:					Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	nessus-plugins
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

MAINTAINER=	olgeni@uli.it

BUILD_DEPENDS=	${LOCALBASE}/include/nessus/config.h:${PORTSDIR}/security/nessus \
		${LOCALBASE}/bin/nmap:${PORTSDIR}/security/nmap
RUN_DEPENDS=	nmap:${PORTSDIR}/security/nmap \
		lynx:${PORTSDIR}/www/lynx

DIST_SUBDIR=	nessus
WRKSRC=		${WRKDIR}/nessus-plugins

GNU_CONFIGURE=	yes

MAN1=		nessus-build.1
MAN8=		nessus-update-plugins.8

.include <bsd.port.mk>
