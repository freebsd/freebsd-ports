# New ports collection makefile for:	pkg_cutleaves
# Date created:		27 July 2003
# Whom:			Stefan Walter <sw@gegenunendlich.de>
#
# $FreeBSD$
#
# This port is self contained in the src directory.
#

PORTNAME=	pkg_cutleaves
PORTVERSION=	20031231
CATEGORIES=	sysutils
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	sw@gegenunendlich.de
COMMENT=	Interactive script for deinstalling 'leaf' packages

RUN_DEPENDS=	${LOCALBASE}/sbin/pkg_deinstall:${PORTSDIR}/sysutils/portupgrade

NO_BUILD=	yes
USE_PERL5=	yes
USE_REINPLACE=	yes

SRC=		${.CURDIR}/src

MAN1=		pkg_cutleaves.1

PLIST_FILES=	sbin/pkg_cutleaves

do-fetch:
	@${DO_NADA}

pre-patch:
	@${CP} ${SRC}/pkg_cutleaves ${WRKDIR}/pkg_cutleaves
	@${CP} ${SRC}/pkg_cutleaves.1 ${WRKDIR}/pkg_cutleaves.1

post-patch:
	@${REINPLACE_CMD} -e \
	  's,/usr/local/etc/pkg_leaves.exclude,${PREFIX}/etc/pkg_leaves.exclude,' \
	  ${WRKDIR}/pkg_cutleaves.1
	@${REINPLACE_CMD} -e \
	  's,/usr/local/etc/pkg_leaves.exclude,${PREFIX}/etc/pkg_leaves.exclude,' \
	  ${WRKDIR}/pkg_cutleaves
	@${REINPLACE_CMD} -e \
	  's,/usr/local/sbin/pkg_deinstall,${LOCALBASE}/sbin/pkg_deinstall,' \
	  ${WRKDIR}/pkg_cutleaves
	@${REINPLACE_CMD} -e \
	  's,/usr/local/sbin/pkgdb,${LOCALBASE}/sbin/pkgdb,' \
	  ${WRKDIR}/pkg_cutleaves
	@${REINPLACE_CMD} -e \
	  's,/var/db/pkg,${PKG_DBDIR},' \
	  ${WRKDIR}/pkg_cutleaves
	@${REINPLACE_CMD} -e 's,/usr/bin/perl,${PERL},' \
	  ${WRKDIR}/pkg_cutleaves

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/pkg_cutleaves ${PREFIX}/sbin/pkg_cutleaves
	${INSTALL_MAN} ${WRKDIR}/pkg_cutleaves.1 ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
