# Created by: Heiner Eichmann
# $FreeBSD$

PORTNAME=	streamanalyze
PORTVERSION=	0.4
PORTREVISION=	7
CATEGORIES=	multimedia
MASTER_SITES=	LOCAL/beech

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Shrink-factor calculator for StreamDVD

BROKEN=		No public distfiles

LIB_DEPENDS=	libdvdread.so:${PORTSDIR}/multimedia/libdvdread

WRKSRC=		${WRKDIR}/StreamAnalyze

PLIST_FILES=	bin/streamanalyze
PORTDOCS=	README

post-patch:
	@${REINPLACE_CMD} -e 's|gcc -g -Wall|${CC} ${CFLAGS} -I${LOCALBASE}/include -L${LOCALBASE}/lib|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e '/#include <getopt\.h>/ d' ${WRKSRC}/streamanalyze.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/streamanalyze ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
