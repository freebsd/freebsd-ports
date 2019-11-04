# Created by: Michael Moll <kvedulv at kvedulv.de>
# $FreeBSD$

PORTNAME=	rbpdf
PORTVERSION=	1.19.8
CATEGORIES=	print rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby library for creating ERB enabled PDF templates

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

RUN_DEPENDS=	rubygem-htmlentities>=0:textproc/rubygem-htmlentities \
		rubygem-rbpdf-font>=${PORTVERSION:R}.0<1.20:print/rubygem-rbpdf-font

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
