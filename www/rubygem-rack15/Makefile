# $FreeBSD$

# XXX: If updating this port, please check compatibality with at least the following ports,
# XXX: preferably, the full rubygem-* tree.  rack version requirements are specified with ~>
# XXX: which requires *EXACTLY* that version.
#
# 	www/rubygem-actionpack
# 	www/rubygem-innate

PORTNAME=	rack
PORTVERSION=	1.5.2
PORTEPOCH=	3
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	15

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Rack, a Ruby Webserver Interface

LICENSE=	MIT

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PORTSCOUT=	limit:^1\.5

# avoid duplicate file from www/rubygem-rack port
post-install:
	@${RM} ${STAGEDIR}${PREFIX}/bin/rackup

.include <bsd.port.mk>
