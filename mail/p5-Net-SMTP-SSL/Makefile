# $FreeBSD$

PORTNAME=	Net-SMTP-SSL
PORTVERSION=	1.04
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	SSL support for Net::SMTP

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-IO-Socket-SSL>=0:security/p5-IO-Socket-SSL
RUN_DEPENDS:=	${BUILD_DEPENDS}

DEPRECATED=	Deprecated by upstream, use Net::SMTP instead
EXPIRATION_DATE=2017-03-31

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
