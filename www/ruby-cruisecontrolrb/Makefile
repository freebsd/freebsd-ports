# Ports collection makefile for:	ruby-cruisecontrolrb
# Date created:				25 Sep 2007
# Whom:					Philip M. Gollucci <pgollucci@p6m7g8.com>
#
# $FreeBSD$

PORTNAME=	cruisecontrolrb
PORTVERSION=	1.1.0
CATEGORIES=	www devel ruby
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pgollucci@p6m7g8.com
COMMENT=	Continuous Integration Server For Rails Applications

RUN_DEPENDS=	rubygem-mongrel>=1.0.1:${PORTSDIR}/www/rubygem-mongrel \
	svn:${PORTSDIR}/devel/subversion

USE_RC_SUBR=	cruisecontrolrb

NO_BUILD=	yes

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}
CPIOARGS=	--quiet -pdum -R

do-install:
	@ ${INSTALL} -d -m 0755 ${WWWDIR}
	@ cd ${WRKSRC} && ${FIND} . -name \*.bat -o -name \*.orig -o -name \*Changelog -o -print | \
		${CPIO} ${CPIOARGS} ${WWWOWN}:${WWWGRP} ${WWWDIR}

.include <bsd.port.mk>
