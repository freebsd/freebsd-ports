# Created by: Matthias Fechner <mfechner@FreeBSD.org>
# $FreeBSD$

PORTNAME=	apollo_upload_server
DISTVERSION=	2.0.0.beta.3
PORTREVISION=	2
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Apollo-upload-server middleware for rails

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-graphql>=1.7:devel/rubygem-graphql \
		rubygem-rails60>=5.0:www/rubygem-rails60

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/console bin/setup

.include <bsd.port.mk>
