# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	guard
PORTVERSION=	2.12.8
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Command line tool to easily handle events on file system modifications

LICENSE=	MIT

RUN_DEPENDS=	rubygem-formatador>=0.2.4:${PORTSDIR}/devel/rubygem-formatador \
		rubygem-listen>=2.7:${PORTSDIR}/devel/rubygem-listen \
		rubygem-lumberjack>=1.0:${PORTSDIR}/devel/rubygem-lumberjack \
		rubygem-nenv>=0.1:${PORTSDIR}/devel/rubygem-nenv \
		rubygem-notiffany>=0:${PORTSDIR}/devel/rubygem-notiffany \
		rubygem-pry>=0.9.12:${PORTSDIR}/devel/rubygem-pry \
		rubygem-shellany>=0:${PORTSDIR}/sysutils/rubygem-shellany \
		rubygem-thor>=0.18.1:${PORTSDIR}/devel/rubygem-thor

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/guard \
		bin/_guard-core

.include <bsd.port.mk>
