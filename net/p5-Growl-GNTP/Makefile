# $FreeBSD$

PORTNAME=	Growl-GNTP
PORTVERSION=	0.20
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl implementation of the Growl GNTP Protocol (Client Part)

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Crypt-CBC>=0:security/p5-Crypt-CBC \
		p5-Data-UUID>=0:devel/p5-Data-UUID
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild
NO_ARCH=	yes

.include <bsd.port.mk>
