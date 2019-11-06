# Created by: Michael L. Hostbaek (mich@freebsdcluster.org)
# $FreeBSD$

PORTNAME=	slurm
PORTVERSION=	0.3.3
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.wormulon.net/files/slurm/ \
		http://www.raisdorf.net/files/slurm/

MAINTAINER=	mich@FreeBSD.org
COMMENT=	Generic network load monitor

BROKEN=		unfetchable

LICENSE=	GPLv2+

LDFLAGS+=	-lncurses

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	CFLAGS=-I${LOCALBASE}/include LDFLAGS=-L${LOCALBASE}/lib

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/themes/* ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/KEYS ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/FAQ ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
