# New ports collection makefile for:    replex
# Date created:         20 Jan 2004
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	replex
PORTVERSION=	0.0.7
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://www.metzlerbros.org/dvb/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Remultiplex an MPEG2 TS into a PS for DVD

USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_GETOPT_LONG=	yes
CFLAGS+=	-I${LOCALBASE}/include -DO_LARGEFILE=0
MAKE_ENV+=	LDFLAGS="${LDFLAGS}"
TOFIX=		avi.h element.h mpg_common.h pes.h replex.h ringbuffer.h \
		replex.c ts.c

do-install:
	${INSTALL_DATA} ${WRKSRC}/libreplex.a ${PREFIX}/lib/
	${INSTALL_PROGRAM} ${WRKSRC}/replex ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/TODO ${DOCSDIR}/
.endif

do-configure:
.if !exists(/usr/include/stdint.h)
.for i in ${TOFIX}
	@${REINPLACE_CMD} -e 's|stdint.h|sys/types.h|g' ${WRKSRC}/${i}
.endfor
.endif

.include <bsd.port.mk>
