# Created by: Alex Stangl <alex@stangl.us>
# $FreeBSD$

PORTNAME=	portupdate-scan
PORTVERSION=	0.3
CATEGORIES=	ports-mgmt
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	alex@stangl.us
COMMENT=	Display pertinent parts of {PORTSDIR}/UPDATING

NO_BUILD=	yes
USES=		perl5
USE_PERL5=	run

PLIST_FILES=	sbin/portupdate-scan
SRC=		${.CURDIR}/src

MAN8=		portupdate-scan.8

NO_STAGE=	yes
do-install:
	${INSTALL_SCRIPT} ${SRC}/portupdate-scan ${PREFIX}/sbin/portupdate-scan
	${INSTALL_MAN} ${SRC}/portupdate-scan.8 ${MAN8PREFIX}/man/man8

.include <bsd.port.mk>
