# Created by: Horia Racoviceanu <horia@racoviceanu.com>
# $FreeBSD$

PORTNAME=	html2haml
PORTVERSION=	1.0.1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	horia@racoviceanu.com
COMMENT=	Converts HTML into Haml

LICENSE=	MIT

RUN_DEPENDS=	rubygem-erubis>=2.7.0:${PORTSDIR}/www/rubygem-erubis \
		rubygem-haml>=4.0.0:${PORTSDIR}/www/rubygem-haml \
		rubygem-hpricot>=0.8.6:${PORTSDIR}/www/rubygem-hpricot \
		rubygem-ruby_parser>=3.1.1:${PORTSDIR}/devel/rubygem-ruby_parser

USE_RAKE=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/html2haml

.include <bsd.port.mk>
