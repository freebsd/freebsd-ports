# New ports collection makefile for:	emc2
# Date created:        16 December 2003
# Whom:                thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	emc2
PORTVERSION=	2.15
PORTREVISION=	2
CATEGORIES=	math science
MASTER_SITES=	http://www-rocq1.inria.fr/gamma/cdrom/ftp/emc2/
.if !defined(NOPORTDOCS)
DISTFILES=	${PORTNAME}${EXTRACT_SUFX}	\
		${PORTNAME}-doc-en.ps.gz ${PORTNAME}-doc-fr.ps.gz
EXTRACT_ONLY=	${PORTNAME}${EXTRACT_SUFX}
.endif

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A graphic editor of two dimensional geometry and mesh

RESTRICTED=	No resale, contact author for commercial usage

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_XLIB=	yes
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
.for doc in ${PORTNAME}-doc-en.ps.gz ${PORTNAME}-doc-fr.ps.gz
	@${INSTALL_DATA} ${DISTDIR}/${doc} ${DOCSDIR}
.endfor
	@${ECHO_MSG} "===>  Documentation installed in ${DOCSDIR}."
	@${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
	@${ECHO_MSG} "===>  Examples installed in ${EXAMPLESDIR}."
.endif

.include <bsd.port.mk>
