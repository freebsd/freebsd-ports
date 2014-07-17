# $FreeBSD$

PORTNAME=	porteasy
PORTVERSION=	2.8.5
CATEGORIES=	ports-mgmt
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	des@FreeBSD.org
COMMENT=	Tool for fetching and building ports

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USES=		perl5

SRC=		${.CURDIR}/src

do-configure:
	@${SED} "s,%%PREFIX%%,${PREFIX}," ${SRC}/porteasy.pl >${WRKDIR}/porteasy
do-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/porteasy ${STAGEDIR}${PREFIX}/bin/porteasy
	@${INSTALL_MAN} ${SRC}/porteasy.8 ${STAGEDIR}${PREFIX}/man/man8

.include <bsd.port.mk>
