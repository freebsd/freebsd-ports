# Created by: Torsten Zuehlsdorff <ports@toco-domains.de>
# $FreeBSD$

PORTNAME=	premailer
PORTVERSION=	1.11.1
CATEGORIES=	mail rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Improve the rendering of HTML emails

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-addressable>=0:www/rubygem-addressable \
		rubygem-css_parser>=1.6.0:textproc/rubygem-css_parser \
		rubygem-htmlentities>=4.0.0:textproc/rubygem-htmlentities

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/premailer

.include <bsd.port.mk>
