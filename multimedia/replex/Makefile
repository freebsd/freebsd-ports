# $FreeBSD$

PORTNAME=	replex
PORTVERSION=	0.1.6.8
PORTEPOCH=	1
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=dinoex

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Remultiplex an MPEG2 TS into a PS for DVD

NO_STAGE=	yes

USE_GMAKE=	yes
MAKE_ARGS=	CFLAGS="${CFLAGS}" DEFINES="${CPPFLAGS} -DO_LARGEFILE=0 -DVERSION=\\\"$(PORTVERSION)\\\"" \
		LIBS="${LDFLAGS}"

PLIST_FILES=	bin/replex

.if !defined(NOPORTDOCS)
PORTDOCS=	CHANGES README TODO
.endif

post-patch:
	@${GREP} -lR "<stdint\.h>" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|<stdint\.h>|<inttypes.h>|g'
	@${REINPLACE_CMD} -e 's|-m32||' -e \
		's|-L. -lreplex|libreplex.a $${LIBS}|g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/replex ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/TODO ${DOCSDIR}/
.endif

.include <bsd.port.mk>
