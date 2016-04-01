# $FreeBSD$

PORTNAME=	mcollective-nettest-client

COMMENT=	MCollective client to test ICMP and TCP connectivity

# See MASTERDIR for MAINTAINER.

RUN_DEPENDS=	mcollective-nettest-common>=${PORTVERSION}:sysutils/mcollective-nettest-common

MASTERDIR=	${.CURDIR}/../mcollective-nettest-common

PLIST_FILES=	share/mcollective/aggregate/nettest_mma.ddl \
		share/mcollective/aggregate/nettest_mma.rb \
		share/mcollective/application/nettest.rb

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} "aggregate application/*.rb" ${STAGEDIR}${PREFIX}/share/mcollective

.include "${MASTERDIR}/Makefile"
