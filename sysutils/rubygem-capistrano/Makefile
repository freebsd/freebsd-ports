# New ports collection makefile for:	rubygem-capistrano
# Date created:				22 March 2006
# Whom:					Roderick van Domburg <r.s.a.vandomburg@student.utwente.nl>
#
# $FreeBSD$
#

PORTNAME=	capistrano
PORTVERSION=	2.5.9
PORTREVISION=	1
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RF

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	A utility for executing commands in parallel on multiple machines

RUN_DEPENDS=	rubygem-net-ssh-gateway>=1.0.0:${PORTSDIR}/security/rubygem-net-ssh-gateway \
  	rubygem-net-sftp>=2.0.0:${PORTSDIR}/security/rubygem-net-sftp \
	rubygem-net-scp>=1.0.0:${PORTSDIR}/security/rubygem-net-scp \
	rubygem-highline>=1.4.0:${PORTSDIR}/devel/rubygem-highline \
	rubygem-echoe>0:${PORTSDIR}/devel/rubygem-echoe

USE_RUBY=	yes
USE_RAKE=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/cap bin/capify

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
