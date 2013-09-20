# Created by: kaz
# $FreeBSD$

PORTNAME=	vrfy
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://jadawin.tuxaco.net/freebsd/
DISTNAME=	${PORTNAME}

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	Verify mail address

WRKSRC=		${WRKDIR}
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" RES=""
MAN1=		vrfy.1
MANCOMPRESSED=	yes
PLIST_FILES=	bin/vrfy

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/vrfy ${PREFIX}/bin
	${INSTALL_MAN} ${WRKDIR}/${MAN1} ${PREFIX}/man/man1/
	${GZIP_CMD} ${PREFIX}/man/man1/${MAN1}

.include <bsd.port.mk>
