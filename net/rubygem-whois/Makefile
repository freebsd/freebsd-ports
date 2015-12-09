# Created by: Eric Freeman <freebsdports@chillibear.com>
# $FreeBSD$

PORTNAME=	whois
PORTVERSION=	3.6.4
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby whois library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-activesupport>=3:${PORTSDIR}/devel/rubygem-activesupport

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/whoisrb

.include <bsd.port.mk>
