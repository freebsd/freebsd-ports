# New ports collection makefile for:	2.2.1R to 2.2-stable upgrade kit
# Date created:		18 Apr 1997
# Whom:			asami
#
# $FreeBSD$
#

PORTNAME=	221upgrade
PORTVERSION=	1998.03.08
CATEGORIES=	misc
DISTFILES=	# empty

MAINTAINER=	asami@FreeBSD.org

.include <bsd.port.pre.mk>

.if !defined(PACKAGE_BUILDING)
BROKEN=		this \"port\" is for building packages for distribution only, please get the package from http://www.freebsd.org/ports/ if you need an upgrade
.elif ${OSVERSION} >= 300000
FORBIDDEN=	this needs to be built on a 2.2-stable system
.endif
NO_MTREE=	yes
PREFIX=		/
NO_BUILD=	yes
PKGINSTALL=	${WRKDIR}/INSTALL

do-install:
	${SED} -e "s/%%VERSION%%/${BSDPORTMKVERSION}/" ${PKGDIR}/INSTALL \
		> ${PKGINSTALL}

deinstall:
	@${ECHO} "You can't delete this port."
	@${FALSE}

.include <bsd.port.post.mk>
