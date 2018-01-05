# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rdf
PORTVERSION=	3.0.1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Pure-Ruby library for working with RDF data

LICENSE=	UNLICENSE
LICENSE_FILE=	${WRKSRC}/UNLICENSE

RUN_DEPENDS=	rubygem-hamster>=3.0:devel/rubygem-hamster \
		rubygem-link_header>=0.0.8:www/rubygem-link_header

USES=		gem
USE_RUBY=	yes
NO_ARCH=	yes

PLIST_FILES=	bin/rdf

.include <bsd.port.mk>
