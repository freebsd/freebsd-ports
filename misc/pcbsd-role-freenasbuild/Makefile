# New ports collection makefile for:	pcbsd-freenas-build
#
# $FreeBSD$
#

PORTNAME=	pcbsd-role-freenasbuild
PORTVERSION=	1416503799
CATEGORIES=	misc
MASTER_SITES=	# empty
DISTFILES=	# none

MAINTAINER=	kris@pcbsd.org
COMMENT=	Role which installs packages to do FreeNAS builds

RUN_DEPENDS=	poudriere-devel>=0:${PORTSDIR}/ports-mgmt/poudriere-devel \
		git>=0:${PORTSDIR}/devel/git \
		cdrtools>=0:${PORTSDIR}/sysutils/cdrtools \
		grub2-pcbsd>=0:${PORTSDIR}/sysutils/grub2-pcbsd \
		xorriso>=0:${PORTSDIR}/sysutils/xorriso \
		npm>=0:${PORTSDIR}/www/npm \
		gmake>=0:${PORTSDIR}/devel/gmake \
		python>=0:${PORTSDIR}/lang/python \
		pxz>=0:${PORTSDIR}/archivers/pxz

NO_BUILD=	yes

do-install:
	${DO_NADA}

.include <bsd.port.mk>
