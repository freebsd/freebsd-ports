# $FreeBSD$

PORTNAME=	Role-REST-Client
PORTVERSION=	0.18
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:KAARE
PKGNAMEPREFIX=	p5-

MAINTAINER=	amontalban@gmail.com
COMMENT=	Perl extension for Rest Client Role

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-Data-Serializer>=0.60:devel/p5-Data-Serializer \
		p5-HTTP-Tiny>=0.056:www/p5-HTTP-Tiny \
		p5-Moo>=1.003000:devel/p5-Moo \
		p5-MooX-HandlesVia>=0.001004:devel/p5-MooX-HandlesVia \
		p5-Type-Tiny>=0.024:devel/p5-Type-Tiny \
		p5-URI-Escape-XS>0.11:www/p5-URI-Escape-XS \
		p5-HTTP-Thin>0:www/p5-HTTP-Thin
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	YES

.include <bsd.port.mk>
