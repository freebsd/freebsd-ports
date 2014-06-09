# Created by: Heiner Eichmann
# $FreeBSD$

PORTNAME=	streamanalyze
PORTVERSION=	0.4
PORTREVISION=	6
CATEGORIES=	multimedia
MASTER_SITES=	CENKES LOCAL/beech

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Shrink-factor calculator for StreamDVD

LIB_DEPENDS=	libdvdread.so:${PORTSDIR}/multimedia/libdvdread

WRKSRC=		${WRKDIR}/StreamAnalyze

PLIST_FILES=	bin/streamanalyze
PORTDOCS=	README

post-patch:
	@${REINPLACE_CMD} -e 's|gcc -g -Wall|${CC} ${CFLAGS} -I${LOCALBASE}/include -L${LOCALBASE}/lib|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e '/#include <getopt\.h>/ d' ${WRKSRC}/streamanalyze.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/streamanalyze ${STAGEDIR}${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
