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
NO_ARCH=	yes

PLIST_FILES=	bin/cvs-safesh \
		bin/safesh \
		bin/safeshinstall \
		bin/scpsh \
		man/man1/safesh.1.gz

# XXX Anybody that know how to create manlinks from ports easily, please
# contact me.

do-install:
	${INSTALL_SCRIPT} ${FILESDIR}/${PORTNAME}.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_SCRIPT} ${FILESDIR}/cvs-safesh.sh ${STAGEDIR}${PREFIX}/bin/cvs-safesh
	${INSTALL_MAN} ${FILESDIR}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/man/man1
	${LN} -sf ${PORTNAME} ${STAGEDIR}${PREFIX}/bin/scpsh
	${LN} -sf ${PORTNAME} ${STAGEDIR}${PREFIX}/bin/safeshinstall

.include <bsd.port.mk>
