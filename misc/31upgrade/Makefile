# New ports collection makefile for:	3.1R to 3-stable upgrade kit
# Version required:	n/a
# Date created:		8 Mar 1999
# Whom:			asami
#
# $FreeBSD$
#

DISTNAME=	31upgrade-1999.05.20
CATEGORIES=	misc
DISTFILES=	# empty

MAINTAINER=	asami@FreeBSD.org

.include <bsd.port.pre.mk>

.if !defined(PACKAGE_BUILDING)
BROKEN=		this \"port\" is for building packages for distribution only, please get the package from http://www.freebsd.org/ports/ if you need an upgrade
.elif ${OSVERSION} < 310000
FORBIDDEN=	this needs to be built on a 3-stable system
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
