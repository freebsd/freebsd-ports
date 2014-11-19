# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xe-guest-utilities
PORTVERSION=	6.0.2
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/${GIT_ACCOUNT}/${GIT_PROJECT}/tarball/${GIT_VERSION}/
DISTNAME=	${GIT_ACCOUNT}-${GIT_PROJECT}-${GIT_VERSION}

MAINTAINER=	feld@FreeBSD.org
COMMENT=	FreeBSD VM tools for Citrix XenServer and XCP

RUN_DEPENDS=	xen-tools>0:${PORTSDIR}/sysutils/xen-tools

GIT_ACCOUNT=	felderado
GIT_PROJECT=	freebsd-xen-tools-scripts
GIT_VERSION=	8cc7fe1
GITSRC=		${WRKDIR}/${GIT_ACCOUNT}-${GIT_PROJECT}-${GIT_VERSION}/src/

USES=		gmake python
USE_RC_SUBR=	xenguest

ONLY_FOR_ARCHS=		amd64 i386
ONLY_FOR_ARCHS_REASON=	"Requires i386 XEN or amd64 XENHVM kernels"

PLIST_FILES=	sbin/xe-daemon \
		sbin/xe-update-guest-attrs

do-build:
	@${DO_NADA}

do-install:
	${INSTALL_SCRIPT} ${GITSRC}/sbin/xe-daemon ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${GITSRC}/sbin/xe-update-guest-attrs ${STAGEDIR}${PREFIX}/sbin

.include <bsd.port.mk>
