# New ports collection makefile for:   portcheck
# Date created:        01 January 2007
# Whom:                Kim Naim Lesmer <naim@usebsd.com>
#
# $FreeBSD$
#

PORTNAME=	portcheck
PORTVERSION=	1.12
CATEGORIES=	ports-mgmt
MASTER_SITES=	http://www.usebsd.com/pub/portcheck/files/ \
		http://www.bitcare.dk/pub/portcheck/files/
EXTRACT_SUFX=	.tbz

MAINTAINER=	naim@usebsd.com
COMMENT=	Maintains the ports tree and checks up the installed packages

RUN_DEPENDS=	${LOCALBASE}/sbin/portaudit:${PORTSDIR}/ports-mgmt/portaudit

PLIST_FILES=	bin/portcheck
MAN1=		portcheck.1
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

do-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/portcheck ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKDIR}/portcheck.1 ${MAN8PREFIX}/man/man1
	@${ECHO} ""
	@${ECHO} "See 'man portcheck' for information about usage."
	@${ECHO} ""

.include <bsd.port.pre.mk>
.if ${OSVERSION} < 504104
IGNORE=	doesn't work on our sstem, it needs portsnap, please update your system to at least 5-STABLE
.endif

.include <bsd.port.post.mk>
