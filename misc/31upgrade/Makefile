# New ports collection makefile for:	3.1R to 3-stable upgrade kit
# Date created:		8 Mar 1999
# Whom:			asami
#
# $FreeBSD$
#

PORTNAME=	31upgrade
PORTVERSION=	2000.02.02
CATEGORIES=	misc
DISTFILES=	# empty

MAINTAINER=	asami@FreeBSD.org

.include <bsd.port.pre.mk>

.if !defined(PACKAGE_BUILDING)
BROKEN=		this \"port\" is for building packages for distribution only, please get the package from http://www.freebsd.org/ports/ if you need an upgrade
.elif ${OSVERSION} >= 400000
# test for ${OSVERSION} >= 340000 removed -- it triggers a bug in old make
FORBIDDEN=	this needs to be built on a recent 3-stable system
.endif
NO_MTREE=	yes
PREFIX=		/
NO_BUILD=	yes
PKGINSTALL=	${WRKDIR}/INSTALL
DATE!=		cat /var/db/port.mkversion

do-install:
	${SED} -e "s/%%VERSION%%/${DATE}/" ${PKGDIR}/INSTALL \
		> ${PKGINSTALL}

deinstall:
	@${ECHO} "You can't delete this port."
	@${FALSE}

.include <bsd.port.post.mk>
