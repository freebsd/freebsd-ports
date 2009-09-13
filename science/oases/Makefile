# ex:ts=8
# Ports collection makefile for:	oaeses
# Date created:			May 27, 2002
# Whom:				Heiner Strauss <heiner@bilch.com>
#
# $FreeBSD$
#

PORTNAME=	oases
PORTVERSION=	2.2
PORTREVISION=	6
CATEGORIES=	science
MASTER_SITES=	ftp://keel.mit.edu/pub/Oases/
DISTNAME=	oases_Mar-28-2002

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ocean Acoustics and Seismic Exploration Synthesis

WRKSRC=		${WRKDIR}/Oases_export

USE_XORG=	x11
MAKE_ENV+=	OASES_ROOT="${WRKSRC}" HOSTTYPE=FreeBSD OSTYPE=FreeBSD

USE_FORTRAN=	yes

SCRIPT=		avbeam bistat cplot mplot mtvplot multmtv oasn oasp oasr \
		oass oassp oast plp2mtv
EXAMPLE=	mfp mfp_geo noise pulse rcoef rd_test rdloss rdpulse \
		scat scatp tloss volume

post-patch:
	@${REINPLACE_CMD} -e 's|%%FC%%|${FC}|g ; \
		 s|%%CC%%|${CC}|g ; \
		 s|%%FFLAGS%%|${FFLAGS}|g ; \
		 s|%%CFLAGS%%|${CFLAGS}|g ; \
		 s|%%LDFLAGS%%|${LDFLAGS}|g ; \
		 s|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/FreeBSD-FreeBSD/* ${PREFIX}/bin
.for script in ${SCRIPT}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${script} ${PREFIX}/bin
.endfor
	${INSTALL_DATA} ${WRKSRC}/lib/FreeBSD-FreeBSD/*.a ${PREFIX}/lib
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${TAR} -C ${WRKSRC}/doc -cf - . | \
		${TAR} -C ${DOCSDIR} --unlink -xf -
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
.for dir in ${EXAMPLE}
	${TAR} -C ${WRKSRC} -cf - ${dir} | \
		${TAR} -C ${EXAMPLESDIR} --unlink -xf -
.endfor
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
