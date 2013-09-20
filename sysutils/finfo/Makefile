# Created by: Michael L. Hostbaek (mich@freebsdcluster.org)
# $FreeBSD$

PORTNAME=	finfo
PORTVERSION=	0.1
CATEGORIES=	sysutils
MASTER_SITES=	http://freebsdcluster.org/~mich/software/

MAINTAINER=	mich@FreeBSD.org
COMMENT=	Finfo displays potentially useful information about a file

PLIST_FILES=	bin/finfo
MAN1=		finfo.1

NO_STAGE=	yes
do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} -o ${PORTNAME} ${PORTNAME}.c)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1.gz ${PREFIX}/man/man1/

.include <bsd.port.mk>
