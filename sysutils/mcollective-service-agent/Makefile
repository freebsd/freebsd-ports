# $FreeBSD$

PORTNAME=	mcollective-service-agent

COMMENT=	MCollective agent to manage the OS Services

# See MASTERDIR for MAINTAINER.

RUN_DEPENDS=	mcollective-service-common>=${PORTVERSION}:sysutils/mcollective-service-common

MASTERDIR=	${.CURDIR}/../mcollective-service-common

PLIST_FILES=	share/mcollective/agent/service.rb

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} "agent/*.rb" ${STAGEDIR}${PREFIX}/share/mcollective

.include "${MASTERDIR}/Makefile"
