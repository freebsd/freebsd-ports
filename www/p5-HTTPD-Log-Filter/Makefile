# New ports collection makefile for:	HTTPD::Log::Filter
# Date created:		15 Feb 2002
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	HTTPD-Log-Filter
PORTVERSION=	1.07
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/A/AW/AWRIGLEY
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/IO/Zlib.pm:${PORTSDIR}/archivers/p5-IO-Zlib
RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/IO/Zlib.pm:${PORTSDIR}/archivers/p5-IO-Zlib

PERL_CONFIGURE=	yes
MAN1=		exclude_robots.1
MAN3=		HTTPD::Log::Filter.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
