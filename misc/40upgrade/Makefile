# New ports collection makefile for:	4.0R to 4-stable upgrade kit
# Date created:		11 Jul 2000
# Whom:			asami
#
# $FreeBSD$
#

PORTNAME=	40upgrade
PORTVERSION=	2000.11.01
CATEGORIES=	misc
DISTFILES=	# empty

MAINTAINER=	asami@FreeBSD.org

FORBIDDEN=	something wrong with shared library

.include <bsd.port.pre.mk>

.if !defined(PACKAGE_BUILDING)
BROKEN=		this \"port\" is for building packages for distribution only, please get the package from http://www.freebsd.org/ports/ if you need an upgrade
.elif ${OSVERSION} < 400020 || ${OSVERSION} >= 500000
FORBIDDEN=	this needs to be built on a recent 4-stable system
.endif
NO_MTREE=	yes
PREFIX=		/
NO_BUILD=	yes
PKGINSTALL=	${WRKDIR}/INSTALL
DATE!=		cat /var/db/port.mkversion
MAN1=		pkg_add.1 pkg_create.1 pkg_delete.1 pkg_info.1 pkg_version.1
MANPREFIX=	${PREFIX}usr/share
MANCOMPRESSED=	maybe

do-install:
	${SED} -e "s/%%VERSION%%/${DATE}/" ${PKGDIR}/pkg-install \
		> ${PKGINSTALL}

deinstall:
	@${ECHO} "You can't delete this port."
	@${FALSE}

.include <bsd.port.post.mk>
