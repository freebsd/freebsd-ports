# Ports collection makefile for:  ctrace
# Date created:			  24 Aug 2001
# Whom:				  Kris Kennaway <kris@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	ctrace
PORTVERSION=	0.9
CATEGORIES=	net
MASTER_SITES=	http://www.pratyeka.org/ctrace/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multiprotocol traceroute tool

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Net/RawIP.pm:${PORTSDIR}/net/p5-Net-RawIP
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Net/RawIP.pm:${PORTSDIR}/net/p5-Net-RawIP \
		${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww

NO_BUILD=	yes
USE_BZIP2=	yes

MAN1=		ctrace.1
PLIST_FILES=	sbin/ctrace

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ctrace ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/ctrace.man ${PREFIX}/man/man1/ctrace.1

.include <bsd.port.mk>
