# Created by: eivind
# $FreeBSD$

PORTNAME=	safesh
PORTVERSION=	1.5
CATEGORIES=	security
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Authentication manager for OpenSSH (making secure auth easier)

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

SRC=		${.CURDIR}/src

# XXX Anybody that know how to create manlinks from ports easily, please
# contact me.

do-fetch:
	@${DO_NADA}

do-install:
	@${INSTALL_SCRIPT} ${SRC}/${PORTNAME}.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${INSTALL_SCRIPT} ${SRC}/cvs-safesh.sh ${STAGEDIR}${PREFIX}/bin/cvs-safesh
	@${INSTALL_MAN} ${SRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/man/man1
	@${LN} -sf ${PORTNAME} ${STAGEDIR}${PREFIX}/bin/scpsh
	@${LN} -sf ${PORTNAME} ${STAGEDIR}${PREFIX}/bin/safeshinstall

.include <bsd.port.mk>
