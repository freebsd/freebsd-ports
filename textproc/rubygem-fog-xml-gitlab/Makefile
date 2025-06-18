PORTNAME=	fog-xml
PORTVERSION=	0.1.5
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Extraction of the XML parsing tools shared among 'fog' providers
WWW=		https://github.com/fog/fog-xml

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-fog-core-gitlab>=0:devel/rubygem-fog-core-gitlab \
		rubygem-nokogiri>=1.5.11<2.0.0:textproc/rubygem-nokogiri

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
