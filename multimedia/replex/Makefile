# New ports collection makefile for:    replex
# Date created:         20 Jan 2004
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	replex
PORTVERSION=	0.1.6.8
PORTEPOCH=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://www.metzlerbros.org/dvb/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Remultiplex an MPEG2 TS into a PS for DVD

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
