# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	httparty
PORTVERSION=	0.13.5
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby Library that Makes HTTP Fun Again

LICENSE=	MIT

RUN_DEPENDS=	rubygem-json>=1.8:${PORTSDIR}/devel/rubygem-json \
		rubygem-multi_xml>=0.5.2:${PORTSDIR}/textproc/rubygem-multi_xml

NO_ARCH=	yes

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/httparty

.include <bsd.port.mk>
