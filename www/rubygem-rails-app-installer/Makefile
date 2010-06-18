# New ports collection makefile for:	www/rubygem-rails-app-installer
# Date created:				15 September 2006
# Whom:					Geraud Continsouzas <geraud@gcu.info>
#
# $FreeBSD$
#

PORTNAME=	rails-app-installer
PORTVERSION=	0.2.0
CATEGORIES=	www rubygems
MASTER_SITES=	RF
MASTER_SITE_SUBDIR=	rails-installer

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An installer for Rails apps

RUN_DEPENDS=	rubygem-sqlite3>=1.1.0:${PORTSDIR}/databases/rubygem-sqlite3 \
		rubygem-mongrel>=0.3.13:${PORTSDIR}/www/rubygem-mongrel \
		rubygem-mongrel_cluster>=0.2.0:${PORTSDIR}/www/rubygem-mongrel_cluster

USE_RUBY=	yes
USE_RAKE=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/rails-app-installer-setup \
		bin/rails-backup \
		bin/rails-restore

.include <bsd.port.mk>
