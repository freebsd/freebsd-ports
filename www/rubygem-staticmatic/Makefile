# Created by: Robert Gogolok <gogo@cs.uni-sb.de>
# $FreeBSD$

PORTNAME=	staticmatic
PORTVERSION=	0.11.1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	gogo@cs.uni-sb.de
COMMENT=	Manage static websites using Haml and Sass

RUN_DEPENDS=	rubygem-haml>=2.0.0:${PORTSDIR}/www/rubygem-haml \
		rubygem-mongrel>=1.1.5:${PORTSDIR}/www/rubygem-mongrel \
		rubygem-rack>=1.0:${PORTSDIR}/www/rubygem-rack \
		rubygem-compass>=0.10.0:${PORTSDIR}/textproc/rubygem-compass

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/staticmatic

NO_STAGE=	yes
.include <bsd.port.mk>
