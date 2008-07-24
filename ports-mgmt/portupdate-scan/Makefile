# New ports collection makefile for:	portupdate-scan
# Date created:				08 November 2007
# Whom:					Alex Stangl <alex@stangl.us>
#
# $FreeBSD$
#
# This port is self contained in the files directory.

PORTNAME=	portupdate-scan
PORTVERSION=	0.3
CATEGORIES=	ports-mgmt
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	alex@stangl.us
COMMENT=	Display pertinent parts of {PORTSDIR}/UPDATING

NO_BUILD=	yes
USE_PERL5_RUN=	yes

PLIST_FILES=	sbin/portupdate-scan
SRC=		${.CURDIR}/src

MAN8=		portupdate-scan.8

do-install:
	${INSTALL_SCRIPT} ${SRC}/portupdate-scan ${PREFIX}/sbin/portupdate-scan
	${INSTALL_MAN} ${SRC}/portupdate-scan.8 ${MAN8PREFIX}/man/man8

.include <bsd.port.mk>
