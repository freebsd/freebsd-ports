# $FreeBSD$

PORTNAME=	mcollective-service-client

COMMENT=	MCollective client to manage the OS Services

# See MASTERDIR for MAINTAINER.

RUN_DEPENDS=	mcollective-service-common>=${PORTVERSION}:sysutils/mcollective-service-common

MASTERDIR=	${.CURDIR}/../mcollective-service-common

PLIST_FILES=	share/mcollective/application/service.rb

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} "application/*" ${STAGEDIR}${PREFIX}/share/mcollective

.include "${MASTERDIR}/Makefile"
