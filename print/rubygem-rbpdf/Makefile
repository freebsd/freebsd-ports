PORTNAME=	rbpdf
PORTVERSION=	1.21.2
CATEGORIES=	print rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby library for creating ERB enabled PDF templates
WWW=		https://github.com/naitoh/rbpdf

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

RUN_DEPENDS=	rubygem-htmlentities>=0:textproc/rubygem-htmlentities \
		rubygem-rbpdf-font>=1.19.0<1.20:print/rubygem-rbpdf-font

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
