# Ports collection makefile for:	rubygem-sinatra
# Date created:				2008-11-02
# Whom:					Daniel Roethlisberger <daniel@roe.ch>
#
# $FreeBSD$

PORTNAME=	sinatra
PORTVERSION=	0.9.1.1
CATEGORIES=	www rubygems
MASTER_SITES=	RF

MAINTAINER=	daniel@roe.ch
COMMENT=	A classy web development framework in ruby

BUILD_DEPENDS=	rubygem-rack>=0.9.1:${PORTSDIR}/www/rubygem-rack
RUN_DEPENDS=	rubygem-rack>=0.9.1:${PORTSDIR}/www/rubygem-rack

BROKEN=		does not install: sinatra requires rack (>= 0.9.1, < 1.0, runtime)

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
