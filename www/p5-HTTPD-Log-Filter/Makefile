# $FreeBSD$

PORTNAME=	HTTPD-Log-Filter
PORTVERSION=	1.08
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:AWRIGLEY
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl module to filter entries out of an httpd log

BUILD_DEPENDS=	p5-IO-Zlib>=0:${PORTSDIR}/archivers/p5-IO-Zlib
RUN_DEPENDS=	p5-IO-Zlib>=0:${PORTSDIR}/archivers/p5-IO-Zlib

USES=		perl5
USE_PERL5=	configure
MAN1=		exclude_robots.1
MAN3=		HTTPD::Log::Filter.3

NO_STAGE=	yes
.include <bsd.port.mk>
