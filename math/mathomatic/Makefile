# New ports collection makefile for:	Mathomatic
# Date created:			Tue Mar 22 10:05:25 CET 2005
# Whom:				Roman Neuhauser <neuhauser@sigpipe.cz>
#
# $FreeBSD$
#

PORTNAME=	mathomatic
PORTVERSION=	15.0.0
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://www.panix.com/~gesslein/ \
		CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Highly portable, general purpose CAS (Computer Algebra System)

USE_BZIP2=	yes
MAKE_JOBS_SAFE=	yes

MAKEFILE=	makefile
MAKE_ARGS=	-DREADLINE

PORTDOCS=	*

MAN1=		mathomatic.1

post-patch:
	@${REINPLACE_CMD} -e '/^CFLAGS/ s|-O||' ${WRKSRC}/makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mathomatic ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/mathomatic.1 ${PREFIX}/man/man1
	${MKDIR} ${PREFIX}/share/applications ${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/icons/mathomatic.desktop \
		${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/icons/mathomatic.png ${PREFIX}/share/pixmaps
.if !defined(NOPORTDOCS)
.for d in m4 tests factorial
	${MKDIR} ${DOCSDIR}/${d}
	${INSTALL_DATA} ${WRKSRC}/${d}/* ${DOCSDIR}/${d}
.endfor
	${MKDIR} ${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}/html
.for f in AUTHORS README.txt changes.txt
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
