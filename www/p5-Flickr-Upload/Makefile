# Created by: ijliao
# $FreeBSD$

PORTNAME=	Flickr-Upload
PORTVERSION=	1.32
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Upload images to flickr.com

BUILD_DEPENDS=	p5-Flickr-API>=0:${PORTSDIR}/www/p5-Flickr-API \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-XML-Parser-Lite-Tree>=0:${PORTSDIR}/textproc/p5-XML-Parser-Lite-Tree
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
