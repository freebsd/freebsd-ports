# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	parslet
PORTVERSION=	1.6.1
PORTREVISION=	1
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Parser construction library with great error reporting in Ruby

LICENSE=	MIT

RUN_DEPENDS=	rubygem-blankslate>=2:${PORTSDIR}/devel/rubygem-blankslate

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

post-patch:
	@${REINPLACE_CMD} -e '17 s|~>|>=|' ${WRKSRC}/${GEM_NAME}.gemspec

.include <bsd.port.mk>
