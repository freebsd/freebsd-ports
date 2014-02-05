# Created by: Daniel Roethlisberger <daniel@roe.ch>
# $FreeBSD$

PORTNAME=	sinatra
PORTVERSION=	1.4.4
PORTREVISION=	1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Classy web development framework in ruby

LICENSE=	MIT

RUN_DEPENDS=	rubygem-rack>=1.4:${PORTSDIR}/www/rubygem-rack \
		rubygem-rack-protection>=1.4:${PORTSDIR}/www/rubygem-rack-protection \
		rubygem-tilt>=1.3.4:${PORTSDIR}/devel/rubygem-tilt

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

post-patch:
	@${REINPLACE_CMD} -e '34 s|~>|">="|' ${WRKSRC}/${GEM_NAME}.gemspec

.include <bsd.port.mk>
