# $FreeBSD$

PORTNAME=	mcollective-nettest-agent

COMMENT=	MCollective agent to test ICMP and TCP connectivity

# See MASTERDIR for MAINTAINER.

RUN_DEPENDS=	mcollective-nettest-common>=${PORTVERSION}:sysutils/mcollective-nettest-common \
		rubygem-net-ping>=1:net/rubygem-net-ping

MASTERDIR=	${.CURDIR}/../mcollective-nettest-common

PLIST_FILES=	share/mcollective/agent/nettest.rb

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} "agent/*.rb" ${STAGEDIR}${PREFIX}/share/mcollective

.include "${MASTERDIR}/Makefile"
