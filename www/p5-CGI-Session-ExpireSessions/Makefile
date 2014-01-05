# Created by: Gerard Seibert <gerard@seibercom.net>
# $FreeBSD$

PORTNAME=	CGI-Session-ExpireSessions
PORTVERSION=	1.12
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CGI
PKGNAMEPREFIX=	p5-
EXTRACT_SUFX=	.tgz

MAINTAINER=	gerard@seibercom.net
COMMENT=	Perl module to delete expired CGI::Session-type sessions

RUN_DEPENDS=	p5-CGI-Session>=4.14:${PORTSDIR}/www/p5-CGI-Session
TEST_DEPENDS=	p5-Test-Pod>=0:${PORTSDIR}/devel/p5-Test-Pod

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
