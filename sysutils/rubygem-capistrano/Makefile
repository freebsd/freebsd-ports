# Created by: Roderick van Domburg <r.s.a.vandomburg@student.utwente.nl>
# $FreeBSD$

PORTNAME=	capistrano
PORTVERSION=	3.0.1
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Utility for executing commands in parallel on multiple machines

LICENSE=	MIT

RUN_DEPENDS=	rubygem-i18n>=0:${PORTSDIR}/devel/rubygem-i18n \
		rubygem-rake>=10:${PORTSDIR}/devel/rubygem-rake \
		rubygem-sshkit>=0.0.23:${PORTSDIR}/security/rubygem-sshkit

USE_RUBY=	yes
USE_RAKE=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/cap

post-install:
	@${ECHO_MSG} "======================================================================"
	@${ECHO_MSG}
	@${ECHO_MSG} "If upgrading/switching from SwitchTower to Capistrano, be sure to:"
	@${ECHO_MSG} " - pkg_delete ${PKG_DBDIR}/rubygem-switchtower-*"
	@${ECHO_MSG} " - for all Rails projects, execute \"cap -A .\", keeping deploy.rb"
	@${ECHO_MSG} " - for all Rails projects, remove lib/tasks/switchtower.rake"
	@${ECHO_MSG}
	@${ECHO_MSG} "======================================================================"

.include <bsd.port.mk>
