# Created by: ijliao
# $FreeBSD$

PORTNAME=	Flickr-Upload
PORTVERSION=	1.60
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:S|0$||}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Upload images to flickr.com

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Flickr-API>=0:www/p5-Flickr-API \
		p5-XML-Parser-Lite-Tree>=0:textproc/p5-XML-Parser-Lite-Tree \
		p5-libwww>=0:www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
