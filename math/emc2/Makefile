# New ports collection makefile for:	emc2
# Date created:        16 December 2003
# Whom:                thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	emc2
PORTVERSION=	2.15
PORTREVISION=	5
CATEGORIES=	math science
MASTER_SITES=	http://pauillac.inria.fr/cdrom_a_graver/ftp/emc2/
DISTFILES=	${PORTNAME}${EXTRACT_SUFX}
.if !defined(NOPORTDOCS)
DISTFILES+=	${PORTNAME}-doc-en.ps.gz ${PORTNAME}-doc-fr.ps.gz
EXTRACT_ONLY=	${PORTNAME}${EXTRACT_SUFX}
.endif

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A graphic editor of two dimensional geometry and mesh

RESTRICTED=	No resale, contact author for commercial usage

BROKEN=		size mismatch

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_XORG=	x11
USE_GMAKE=	yes
ALL_TARGET=	${PORTNAME}

.if defined(LANG) && ${LANG:Mfr*} != ""
CFLAGS+=	-DFRENCH
.endif

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/emc2
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/COPYRIGHT ${DOCSDIR}
	@${GZCAT} ${DISTDIR}/${PORTNAME}-doc-en.ps.gz > ${DOCSDIR}/${PORTNAME}-en.ps
	@${GZCAT} ${DISTDIR}/${PORTNAME}-doc-fr.ps.gz > ${DOCSDIR}/${PORTNAME}-fr.ps
	@${ECHO_MSG} "===>  Documentation installed in ${DOCSDIR}."
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
	@${ECHO_MSG} "===>  Examples installed in ${EXAMPLESDIR}."
.endif

.include <bsd.port.mk>
