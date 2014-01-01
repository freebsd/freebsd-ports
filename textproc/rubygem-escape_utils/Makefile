# Created by: Scott Sanders <scott@jssjr.com>
# $FreeBSD$

PORTNAME=	escape_utils
PORTVERSION=	1.0.0
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Faster string escaping routines for your web apps

LICENSE=	MIT

RUN_DEPENDS=	rubygem-actionpack>=0:${PORTSDIR}/www/rubygem-actionpack \
		rubygem-fast_xs>=0:${PORTSDIR}/textproc/rubygem-fast_xs \
		rubygem-haml>=0:${PORTSDIR}/www/rubygem-haml \
		rubygem-minitest>=5:${PORTSDIR}/devel/rubygem-minitest \
		rubygem-rack>=0:${PORTSDIR}/www/rubygem-rack \
		rubygem-rake-compiler>=0.7.5:${PORTSDIR}/devel/rubygem-rake-compiler \
		rubygem-url_escape>=0:${PORTSDIR}/www/rubygem-url_escape

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
