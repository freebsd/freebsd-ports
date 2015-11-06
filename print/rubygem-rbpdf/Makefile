# Created by: Michael Moll <kvedulv at kvedulv.de>
# $FreeBSD$

PORTNAME=	rbpdf
PORTVERSION=	1.18.7
CATEGORIES=	print rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby library for creating ERB enabled PDF templates

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

RUN_DEPENDS=	rubygem-htmlentities>=4.3.1:${PORTSDIR}/textproc/rubygem-htmlentities

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
USES=		dos2unix

.include <bsd.port.mk>
