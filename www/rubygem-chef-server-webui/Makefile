# Ports collection makefile for:	rubygem-chef-server-webui
# Date created:				13 Dec 2011
# Whom:					Scott Sanders <scott@jssjr.com>
#
# $FreeBSD$
#

PORTNAME=	chef-server-webui
PORTVERSION=	0.10.8
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	A systems integration framework

RUN_DEPENDS=	rubygem-coderay>=0:${PORTSDIR}/textproc/rubygem-coderay \
		rubygem-haml>=0:${PORTSDIR}/www/rubygem-haml \
		rubygem-json>=1.4.4:${PORTSDIR}/devel/rubygem-json146 \
		rubygem-merb-assets>=1.1.0:${PORTSDIR}/www/rubygem-merb-assets \
		rubygem-merb-core>=1.1.0:${PORTSDIR}/www/rubygem-merb-core \
		rubygem-merb-haml>=1.1.0:${PORTSDIR}/www/rubygem-merb-haml \
		rubygem-merb-helpers>=1.1.0:${PORTSDIR}/www/rubygem-merb-helpers \
		rubygem-merb-param-protection>=1.1.0:${PORTSDIR}/www/rubygem-merb-param-protection \
		rubygem-openid>=0:${PORTSDIR}/net/rubygem-openid \
		rubygem-thin>=0:${PORTSDIR}/www/rubygem-thin

USE_RUBY=		yes
USE_RUBYGEMS=		yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/chef-server-webui

.include <bsd.port.mk>
