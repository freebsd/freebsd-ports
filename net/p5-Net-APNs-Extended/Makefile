# $FreeBSD$

PORTNAME=	Net-APNs-Extended
PORTVERSION=	0.07
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for APNs that support the extended format

RUN_DEPENDS=	\
	p5-Class-Accessor-Lite>0:${PORTSDIR}/devel/p5-Class-Accessor-Lite \
	p5-JSON-XS>0:${PORTSDIR}/converters/p5-JSON-XS \
	p5-Net-SSLeay>0:${PORTSDIR}/security/p5-Net-SSLeay
BUILD_DEPENDS=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

MAN3=	Net::APNs::Extended.3 \
	Net::APNs::Extended::Feedback.3

NO_STAGE=	yes
.include <bsd.port.mk>
