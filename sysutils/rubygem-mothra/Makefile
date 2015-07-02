# Created by: Jin-Sih, Lin <linpct@gmail.com>
# $FreeBSD$

PORTNAME=	mothra
PORTVERSION=	0.0.3
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	linpct@gmail.com
COMMENT=	FreeBSD send-pr command line tool for Bugzilla system

LICENSE=	MIT

RUN_DEPENDS=	rubygem-colorize>=0.7.3:${PORTSDIR}/devel/rubygem-colorize \
		rubygem-rodzilla>=0.3.6:${PORTSDIR}/devel/rubygem-rodzilla \
		rubygem-thor>=0.19.1:${PORTSDIR}/devel/rubygem-thor

NO_ARCH=	yes

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/mothra

.include <bsd.port.mk>
