# New ports collection makefile for:	rubygem-capistrano
# Date created:				22 March 2006
# Whom:					Roderick van Domburg <r.s.a.vandomburg@student.utwente.nl>
#
# $FreeBSD$
#

PORTNAME=	capistrano
PORTVERSION=	1.4.1
CATEGORIES=	sysutils rubygems
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	r.s.a.vandomburg@nedforce.nl
COMMENT=	A utility for executing commands in parallel on multiple machines

BUILD_DEPENDS=	rake:${PORTSDIR}/devel/rubygem-rake \
		${LOCALBASE}/${SPEC_DIR}/net-sftp-1.1.0.gemspec:${PORTSDIR}/security/rubygem-net-sftp
RUN_DEPENDS=	${BUILD_DEPENDS}

post-install:
	@${ECHO_MSG} "======================================================================"
	@${ECHO_MSG}
	@${ECHO_MSG} "If upgrading/switching from SwitchTower to Capistrano, be sure to:"
	@${ECHO_MSG} " - pkg_delete /var/db/pkg/rubygem-switchtower-*"
	@${ECHO_MSG} " - for all Rails projects, execute \"cap -A .\", keeping deploy.rb"
	@${ECHO_MSG} " - for all Rails projects, remove lib/tasks/switchtower.rake"
	@${ECHO_MSG}
	@${ECHO_MSG} "======================================================================"

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/ruby-gems/Makefile.common"
.include <bsd.port.post.mk>
