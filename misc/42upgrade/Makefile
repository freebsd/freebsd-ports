# New ports collection makefile for:	4.2R to 4-stable upgrade kit
# Date created:		5 Feb 2000
# Whom:			asami
#
# $FreeBSD$
#

PORTNAME=	42upgrade
PORTVERSION=	2000.02.05
CATEGORIES=	misc
DISTFILES=	# empty

MAINTAINER=	asami@FreeBSD.org

.include <bsd.port.pre.mk>

.if !defined(PACKAGE_BUILDING)
BROKEN=		this \"port\" is for building packages for distribution only, please get the package from http://www.freebsd.org/ports/ if you need an upgrade
.elif ${OSVERSION} < 420000 || ${OSVERSION} >= 500000
FORBIDDEN=	this needs to be built on a recent 4-stable system
.endif
NO_MTREE=	yes
PREFIX=		/
NO_BUILD=	yes
PKGINSTALL=	${WRKDIR}/INSTALL
DATE!=		cat /var/db/port.mkversion
MANPREFIX=	${PREFIX}usr/share
MANCOMPRESSED=	maybe

do-install:
	${SED} -e "s/%%VERSION%%/${DATE}/" ${PKGDIR}/pkg-install \
		> ${PKGINSTALL}

deinstall:
	@${ECHO} "You can't delete this port."
	@${FALSE}

.include <bsd.port.post.mk>
