# Created by: Tsung-Han Yeh <snowfly@yuntech.edu.tw>
# $FreeBSD$

PORTNAME=	Net-Flickr-Backup
PORTVERSION=	3.1
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	snowfly@yuntech.edu.tw
COMMENT=	OOP for backing up your Flickr photos locally

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-File-Find-Rule>=0:devel/p5-File-Find-Rule \
		p5-IO-stringy>=2.101:devel/p5-IO-stringy \
		p5-Image-MetaData-JPEG>=0.15:graphics/p5-Image-MetaData-JPEG \
		p5-Net-Flickr-RDF>=2.2:www/p5-Net-Flickr-RDF \
		p5-TimeDate>=1.16:devel/p5-TimeDate \
		p5-Text-Unidecode>=0.04:converters/p5-Text-Unidecode \
		p5-libwww>=1.38:www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
