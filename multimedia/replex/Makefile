# $FreeBSD$

PORTNAME=	replex
PORTVERSION=	0.1.6.8
PORTEPOCH=	1
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=dinoex

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Remultiplex an MPEG2 TS into a PS for DVD

USE_GMAKE=	yes
MAKE_ARGS=	CFLAGS="${CFLAGS}" DEFINES="${CPPFLAGS} -DO_LARGEFILE=0 \
		-DVERSION=\\\"$(PORTVERSION)\\\"" LIBS="${LDFLAGS}"
PLIST_FILES=	bin/replex

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	CHANGES README TODO
.endif

post-patch:
	@${GREP} -lR "<stdint\.h>" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|<stdint\.h>|<inttypes.h>|g'
	@${REINPLACE_CMD} -e 's|-m32||' -e \
		's|-L. -lreplex|libreplex.a $${LIBS}|g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/replex ${STAGEDIR}${PREFIX}/bin/
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/TODO ${STAGEDIR}${DOCSDIR}/
.endif

.include <bsd.port.mk>
