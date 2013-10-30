# Created by: Scott Sanders <scott@jssjr.com>
# $FreeBSD$

PORTNAME=	chef-server-webui
PORTVERSION=	10.24.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	A systems integration framework

RUN_DEPENDS=	rubygem-coderay>=0:${PORTSDIR}/textproc/rubygem-coderay \
		rubygem-extlib>=0.9.16:${PORTSDIR}/devel/rubygem-extlib \
		rubygem-haml>=0:${PORTSDIR}/www/rubygem-haml \
		rubygem-merb-assets>=1.1.0:${PORTSDIR}/www/rubygem-merb-assets \
		rubygem-merb-core>=1.1.0:${PORTSDIR}/www/rubygem-merb-core \
		rubygem-merb-haml>=1.1.0:${PORTSDIR}/www/rubygem-merb-haml \
		rubygem-merb-helpers>=1.1.0:${PORTSDIR}/www/rubygem-merb-helpers \
		rubygem-merb-param-protection>=1.1.0:${PORTSDIR}/www/rubygem-merb-param-protection \
		rubygem-rack>=1.4.5:${PORTSDIR}/www/rubygem-rack \
		rubygem-openid>=0:${PORTSDIR}/net/rubygem-openid \
		rubygem-thin>=0:${PORTSDIR}/www/rubygem-thin

USE_RUBY=		yes
USE_RUBYGEMS=		yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/chef-server-webui

.include <bsd.port.mk>
