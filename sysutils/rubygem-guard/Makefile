# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	guard
PORTVERSION=	2.13.0
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Command line tool to easily handle events on file system modifications

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-formatador>=0.2.4:devel/rubygem-formatador \
		rubygem-listen>=2.7:devel/rubygem-listen \
		rubygem-lumberjack>=1.0:devel/rubygem-lumberjack \
		rubygem-nenv>=0.1:devel/rubygem-nenv \
		rubygem-notiffany>=0:devel/rubygem-notiffany \
		rubygem-pry>=0.9.12:devel/rubygem-pry \
		rubygem-shellany>=0:sysutils/rubygem-shellany \
		rubygem-thor>=0.18.1:devel/rubygem-thor

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/guard \
		bin/_guard-core

.include <bsd.port.mk>
