# New ports collection makefile for:   vida
# Date created:        Thu Apr 17 11:22:35 GMT 2003
# Whom:                mich@freebsdcluster.org
#
# $FreeBSD$
#

PORTNAME=	vida
PORTVERSION=	0.7.1
CATEGORIES=	security
MASTER_SITES=	http://vidatapipe.sourceforge.net/

MAINTAINER=	mich@FreeBSD.org
COMMENT=	Vida is a multi-datapipe handler

BUILD_DEPENDS=	${LOCALBASE}/include/libnet.h:${PORTSDIR}/net/libnet

LDFLAGS+=	-pthread -lncurses -lpcap -lnet

WRKSRC=		${WRKDIR}/${PORTNAME}

do-build:
	cd ${WRKSRC} && \
	${CC} -I${LOCALBASE}/include -L${LOCALBASE}/lib ${CFLAGS} vida.c funz.c dnshijacking.c \
	${LDFLAGS} `libnet-config --defines` -o ${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/vida.1.gz ${PREFIX}/man/man1/

MAN1=		vida.1
MANCOMPRESSED=	yes
PLIST_FILES=	bin/vida

.include <bsd.port.mk>
