# $FreeBSD$

PORTNAME=	Catalyst-Model-LDAP
PORTVERSION=	0.17
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	LDAP model class for Catalyst

BUILD_DEPENDS=	p5-Catalyst-Runtime>=5.7:www/p5-Catalyst-Runtime \
		p5-Class-Accessor>0:devel/p5-Class-Accessor \
		p5-MRO-Compat>0:devel/p5-MRO-Compat \
		p5-Data-Page>0:databases/p5-Data-Page \
		p5-perl-ldap>=0:net/p5-perl-ldap
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
