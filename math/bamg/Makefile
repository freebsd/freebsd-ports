# New ports collection makefile for:	bamg
# Date created:        16 December 2003
# Whom:                thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	bamg
PORTVERSION=	0.68
PORTREVISION=	1
CATEGORIES=	math science
MASTER_SITES=	ftp://ftp.inria.fr/INRIA/Projects/Gamma/bamg/
DISTNAME=	${PORTNAME}-v${PORTVERSION}
.if !defined(NOPORTDOCS)
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${PORTNAME}.ps.gz
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
.endif

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Bidimensional Anisotrope Mesh Generator

RESTRICTED=	No resale, contact author for commercial usage

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_XLIB=	yes
USE_GMAKE=	yes

ALL_TARGET=	world
INSTALL_TARGET=	install-world

MAKE_ENV=	CXX=${CXX} HOSTTYPE=${HOSTTYPE}

BINS=		bamg bamg-g cvmsh2 drawbdmesh
EXDIRS=		NACA012 quadloop square test

.include <bsd.port.pre.mk>

HOSTTYPE!=	${UNAME} -s

post-patch:
	@${MV} ${WRKSRC}/FLAG.linux ${WRKSRC}/FLAG.${HOSTTYPE}
	@${MV} ${WRKSRC}/FLAG.linux.orig ${WRKSRC}/FLAG.linux

post-install:
.for bin in ${BINS}
	@${STRIP_CMD} ${PREFIX}/bin/${bin}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${DISTDIR}/bamg.ps.gz ${DOCSDIR}
	@${ECHO_MSG} "===>  Documentation installed in ${DOCSDIR}."
.for exdir in ${EXDIRS}
	@${MKDIR} ${EXAMPLESDIR}/${exdir}
	@${INSTALL_DATA} ${WRKSRC}/examples/${exdir}/* ${EXAMPLESDIR}/${exdir}
.endfor
	@${FIND} ${EXAMPLESDIR} \( -name "*.pl" -or -name "*.sh" \) -exec ${CHMOD} a+x {} \;
	@${ECHO_MSG} "===>  Examples installed in ${EXAMPLESDIR}."
.endif

.include <bsd.port.post.mk>
