# Created by: Daniel Roethlisberger <daniel@roe.ch>
# $FreeBSD$

PORTNAME=	sinatra
PORTVERSION=	1.4.3
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	A classy web development framework in ruby

RUN_DEPENDS=	rubygem-rack>=1.4:${PORTSDIR}/www/rubygem-rack \
		rubygem-tilt>=1.3.4:${PORTSDIR}/devel/rubygem-tilt \
		rubygem-rack-protection>=1.4:${PORTSDIR}/www/rubygem-rack-protection

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
