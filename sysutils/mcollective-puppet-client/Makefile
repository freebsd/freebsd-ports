# $FreeBSD$

PORTNAME=	mcollective-puppet-client

COMMENT=	MCollective client to manage the Puppet Agent

# See MASTERDIR for MAINTAINER.

RUN_DEPENDS=	mcollective-puppet-common>=${PORTVERSION}:sysutils/mcollective-puppet-common

MASTERDIR=	${.CURDIR}/../mcollective-puppet-common

PLIST_FILES=	share/mcollective/application/puppet.rb \
		share/mcollective/aggregate/boolean_summary.ddl \
		share/mcollective/aggregate/boolean_summary.rb

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} "aggregate application" ${STAGEDIR}${PREFIX}/share/mcollective

.include "${MASTERDIR}/Makefile"
