# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	SOAP-XML-Client
PORTVERSION=	2.8
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Simple frame work for talking with web services

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Class-Accessor>=0:devel/p5-Class-Accessor \
		p5-File-Slurp>=0:devel/p5-File-Slurp \
		p5-SOAP-Data-Builder>=0.8:net/p5-SOAP-Data-Builder \
		p5-SOAP-Lite>=0.67:net/p5-SOAP-Lite \
		p5-XML-LibXML>=0.6:textproc/p5-XML-LibXML
RUN_DEPENDS:=	${BUILD_DEPENDS}

PORTSCOUT=	skipv:2.26

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
