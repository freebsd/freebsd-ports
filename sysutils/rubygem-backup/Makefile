# New ports collection makefile for:	rubygem-backup
# Date created:		2011-10-30
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	backup
PORTVERSION=	3.0.23
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perform backup operations on remote and local environment

RUN_DEPENDS=	rubygem-popen4>=0.1.4:${PORTSDIR}/devel/rubygem-popen4 \
		rubygem-thor>=0.14.6:${PORTSDIR}/devel/rubygem-thor

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/backup

.include <bsd.port.mk>
