# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	t
PORTVERSION=	3.1.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Command-line power tool for Twitter

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-geokit>=1.9:graphics/rubygem-geokit \
		rubygem-htmlentities>=4.3:textproc/rubygem-htmlentities \
		rubygem-launchy>=2.4:devel/rubygem-launchy \
		rubygem-oauth>=0.5.1:net/rubygem-oauth \
		rubygem-retryable>=2.0:devel/rubygem-retryable \
		rubygem-thor>=0.19.1:devel/rubygem-thor \
		rubygem-twitter>=6.0:net/rubygem-twitter

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/t

.include <bsd.port.mk>
