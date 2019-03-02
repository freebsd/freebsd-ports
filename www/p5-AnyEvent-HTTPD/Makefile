# Created by: Mons Anderson <mons@cpan.org>
# $FreeBSD$

PORTNAME=	AnyEvent-HTTPD
PORTVERSION=	0.93
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ELMEX
PKGNAMEPREFIX=	p5-

MAINTAINER=	mons@cpan.org
COMMENT=	Simple lightweight event based web server

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-AnyEvent>=0:devel/p5-AnyEvent \
		p5-Object-Event>=1.21:devel/p5-Object-Event \
		p5-common-sense>=2.0:devel/p5-common-sense \
		p5-URI>=1.40:net/p5-URI

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
