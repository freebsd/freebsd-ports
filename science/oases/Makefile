# ex:ts=8
# Ports collection makefile for:	oaeses
# Date created:			May 27, 2002
# Whom:				Heiner Strauss <heiner@bilch.com>
#
# $FreeBSD$
#

PORTNAME=	oases
PORTVERSION=	2.2
CATEGORIES=	science
MASTER_SITES=	ftp://keel.mit.edu/pub/Oases/
DISTNAME=	oases_Mar-28-2002

MAINTAINER=	ports@FreeBSD.org

USE_XLIB=	yes
WRKSRC=		${WRKDIR}/Oases_export

OASES_ROOT=	${WRKSRC}
SCRIPT=		avbeam bistat cplot mplot mtvplot multmtv oasn oasp oasr \
		oass oassp oast plp2mtv
EXAMPLE=	mfp mfp_geo noise pulse rcoef rd_test rdloss rdpulse \
		scat scatp tloss

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/bin/FreeBSD-FreeBSD/* ${PREFIX}/bin
.for script in ${SCRIPT}
		${INSTALL_SCRIPT} ${WRKSRC}/bin/${script} ${PREFIX}/bin
.endfor
		${INSTALL_DATA} ${WRKSRC}/lib/FreeBSD-FreeBSD/*.a ${PREFIX}/lib
.if !defined(NOPORTDOCS)
		@${MKDIR} ${DOCSDIR}
		${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
		@${CP} -R ${WRKSRC}/doc/ ${DOCSDIR}
		@${MKDIR} ${EXAMPLESDIR}
.for example in ${EXAMPLE}
		@${MKDIR} ${EXAMPLESDIR}/${example}
		${INSTALL_DATA} ${WRKSRC}/${example}/* ${EXAMPLESDIR}/${example}
.endfor
		@${CP} -R ${WRKSRC}/volume ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
