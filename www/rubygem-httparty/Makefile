# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	httparty
PORTVERSION=	0.13.7
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby Library that Makes HTTP Fun Again

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-json>=1.8:devel/rubygem-json \
		rubygem-multi_xml>=0.5.2:textproc/rubygem-multi_xml

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/httparty

.include <bsd.port.mk>
