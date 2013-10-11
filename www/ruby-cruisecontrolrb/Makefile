# $FreeBSD$

PORTNAME=	cruisecontrolrb
PORTVERSION=	1.4.0
PORTREVISION=	1
CATEGORIES=	www devel ruby
MASTER_SITES=	RF
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	cruisecontrol-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Continuous Integration Server For Rails Applications

DEPRECATED=	Does not work with Ruby 1.9
EXPIRATION_DATE=	2013-10-10

RUN_DEPENDS=	rubygem-mongrel>=1.0.1:${PORTSDIR}/www/rubygem-mongrel \
		svn:${PORTSDIR}/devel/subversion

USE_RC_SUBR=	cruisecontrolrb

NO_BUILD=	yes

CPIOARGS=	--quiet -pdum -R

NO_STAGE=	yes
do-install:
	@ ${INSTALL} -d -m 0755 ${WWWDIR}
	@ cd ${WRKSRC} && ${FIND} . -name \*.bat -o -name \*.orig -o -name \*Changelog -o -name .gitignore -o -print | \
		${CPIO} ${CPIOARGS} ${WWWOWN}:${WWWGRP} ${WWWDIR}

.include <bsd.port.mk>
