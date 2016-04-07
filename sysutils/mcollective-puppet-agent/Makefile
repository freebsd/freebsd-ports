# Created by: Anes Mukhametov <anes@anes.su>
# $FreeBSD$

PORTNAME=	mcollective-puppet-agent

COMMENT=	MCollective agent to manage the Puppet Agent

# See MASTERDIR for MAINTAINER.

RUN_DEPENDS=	mcollective-puppet-common>=${PORTVERSION}:sysutils/mcollective-puppet-common

MASTERDIR=	${.CURDIR}/../mcollective-puppet-common

PLIST_FILES=	share/mcollective/agent/puppet.rb

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} "agent/*.rb" ${STAGEDIR}${PREFIX}/share/mcollective

.include "${MASTERDIR}/Makefile"
