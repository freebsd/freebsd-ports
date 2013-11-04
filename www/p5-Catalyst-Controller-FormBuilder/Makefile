# Created by: Lars Balker Rasmussen <lbr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Catalyst-Controller-FormBuilder
PORTVERSION=	0.06
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MSTROUT
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Catalyst FormBuilder Base Controller

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-CGI-FormBuilder>=3.02:${PORTSDIR}/www/p5-CGI-FormBuilder \
		p5-Catalyst-Runtime>=5.7:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Class-Data-Inheritable>=0.04:${PORTSDIR}/devel/p5-Class-Data-Inheritable \
		p5-Class-Inspector>=1.13:${PORTSDIR}/devel/p5-Class-Inspector \
		p5-MRO-Compat>=0.09:${PORTSDIR}/devel/p5-MRO-Compat \
		p5-Test-WWW-Mechanize-Catalyst>=0.37:${PORTSDIR}/devel/p5-Test-WWW-Mechanize-Catalyst \
		p5-Tie-IxHash>=1.21:${PORTSDIR}/devel/p5-Tie-IxHash
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
