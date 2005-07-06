# New ports collection makefile for:	multimedia/lxdvdrip
# Date created:				26.01.2005
# Whom:					Ulrich Spoerlein <q@uni.de>
#
# $FreeBSD$
#

PORTNAME=	lxdvdrip
PORTVERSION=	1.46
CATEGORIES=	multimedia
MASTER_SITES=	http://download.berlios.de/lxdvdrip/
EXTRACT_SUFX=	.tgz

MAINTAINER=	q@galgenberg.net
COMMENT=	Command Line Tool to make a copy from a Video DVD

LIB_DEPENDS=	dvdread.3:${PORTSDIR}/multimedia/libdvdread

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

WRKSRC=		${WRKDIR}/${PORTNAME}

MAN1=		lxdvdrip.1

do-build:
	(cd ${WRKSRC}; \
	${CC} ${CFLAGS} -I${LOCALBASE}/include -L${LOCALBASE}/lib \
	-ldvdread -lm -o lxdvdrip lxdvdrip.c; \
	${CC} ${CFLAGS} -lm -o lxac3scan lxac3scan.c)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lxdvdrip ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/lxac3scan ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/lxdvdrip.1 ${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/doc-pak/lxdvdrip.conf.* ${PREFIX}/etc
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc-pak && ${CP} Changelog* README.* TODO freebsd.doc ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
