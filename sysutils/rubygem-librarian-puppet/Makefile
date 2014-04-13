# $FreeBSD$

PORTNAME=	librarian-puppet
PORTVERSION=	0.9.17
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	ports@robakdesign.com
COMMENT=	Tool for management and bundling Puppet modules

LICENSE=	MIT

RUN_DEPENDS=	${PKGNAMEPREFIX}json>=0:${PORTSDIR}/devel/rubygem-json \
		${PKGNAMEPREFIX}librarian>=0.1.2:${PORTSDIR}/devel/rubygem-librarian

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/librarian-puppet

.include <bsd.port.mk>
