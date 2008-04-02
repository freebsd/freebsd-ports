# New ports collection makefile for:	rubygem-capistrano
# Date created:				22 March 2006
# Whom:					Roderick van Domburg <r.s.a.vandomburg@student.utwente.nl>
#
# $FreeBSD$
#

PORTNAME=	capistrano
PORTVERSION=	2.2.0
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RF

MAINTAINER=	r.s.a.vandomburg@nedforce.nl
COMMENT=	A utility for executing commands in parallel on multiple machines

RUN_DEPENDS=	rake:${PORTSDIR}/devel/rubygem-rake \
		${LOCALBASE}/${SPEC_DIR}/net-sftp-1.1.0.gemspec:${PORTSDIR}/security/rubygem-net-sftp \
		rubygem-highline>=1.4.0:${PORTSDIR}/devel/rubygem-highline

post-install:
	@${ECHO_MSG} "======================================================================"
	@${ECHO_MSG}
	@${ECHO_MSG} "If upgrading/switching from SwitchTower to Capistrano, be sure to:"
	@${ECHO_MSG} " - pkg_delete ${PKG_DBDIR}/rubygem-switchtower-*"
	@${ECHO_MSG} " - for all Rails projects, execute \"cap -A .\", keeping deploy.rb"
	@${ECHO_MSG} " - for all Rails projects, remove lib/tasks/switchtower.rake"
	@${ECHO_MSG}
	@${ECHO_MSG} "======================================================================"

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/ruby-gems/Makefile.common"
.include <bsd.port.post.mk>
