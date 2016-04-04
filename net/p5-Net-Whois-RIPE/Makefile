# Created by: ijliao
# $FreeBSD$

PORTNAME=	Net-Whois-RIPE
PORTVERSION=	2.006
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:AASSAD
PKGNAMEPREFIX=	p5-

MAINTAINER=	mich@FreeBSD.org
COMMENT=	Implementation of RIPE Whois

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Iterator-Util>=0:devel/p5-Iterator-Util
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-WWW-Mechanize>=0:www/p5-WWW-Mechanize

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
