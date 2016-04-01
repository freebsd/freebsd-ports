# Created by: Geoffroy Desvernay <dgeo@centrale-marseille.fr>
# $FreeBSD$

PORTNAME=	URL-Encode
PORTVERSION=	0.03
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:CHANSEN
PKGNAMEPREFIX=	p5-

MAINTAINER=	dgeo@centrale-marseille.fr
COMMENT=	Encoding and decoding of application/x-www-form-urlencoded encoding

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

OPTIONS_DEFINE=	XS
XS_BUILD_DEPENDS=	p5-URL-Encode-XS>=0:www/p5-URL-Encode-XS
XS_RUN_DEPENDS=	${XS_BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
