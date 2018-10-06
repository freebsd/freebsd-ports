# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Geo-GeoNames
PORTVERSION=	1.120
CATEGORIES=	misc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:S|0$||}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perform geographical queries using GeoNames Web Services

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-JSON>=1.14:converters/p5-JSON \
		p5-Mojolicious>=0:www/p5-Mojolicious \
		p5-XML-Simple>=2.13:textproc/p5-XML-Simple

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
