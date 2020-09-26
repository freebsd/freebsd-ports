# Created by: Matthias Fechner <mfechner@FreeBSD.org>
# $FreeBSD$

PORTNAME=	apollo_upload_server
PORTVERSION=	2.0.3
PORTREVISION=	0
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Apollo-upload-server middleware for rails

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-graphql>=1.8:devel/rubygem-graphql \
		rubygem-rails60>=4.2:www/rubygem-rails60

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
