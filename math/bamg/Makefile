# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	bamg
PORTVERSION=	1.01
CATEGORIES=	math science
MASTER_SITES=	http://www.ann.jussieu.fr/hecht/ftp/bamg/
DISTFILES=	${PORTNAME}-v${PORTVERSION}${EXTRACT_SUFX}
.ifndef(NOPORTDOCS)
DISTFILES+=	${PORTNAME}.pdf
EXTRACT_ONLY=	${PORTNAME}-v${PORTVERSION}${EXTRACT_SUFX}
.endif

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Bidimensional Anisotropic Mesh Generator

RESTRICTED=	Contact author personally regarding commercial use

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_XORG=	x11
USES=		gmake
MAKE_JOBS_UNSAFE=	yes

ALL_TARGET=	world
INSTALL_TARGET=	install-world

BINS=		bamg bamg-g cvmsh2 drawbdmesh
EXDIRS=		NACA012 quadloop square test

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.pre-configure:
HOSTTYPE=	${UNAME} -s
MAKE_ENV=	HOSTTYPE=${${HOSTTYPE}}

post-patch:
	@${MV} ${WRKSRC}/FLAG.linux ${WRKSRC}/FLAG.${${HOSTTYPE}}
	@${MV} ${WRKSRC}/FLAG.linux.orig ${WRKSRC}/FLAG.linux

post-install:
.for bin in ${BINS}
	@${STRIP_CMD} ${PREFIX}/bin/${bin}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${DISTDIR}/${PORTNAME}.pdf ${DOCSDIR}
	@${ECHO_MSG} "===>  Documentation installed in ${DOCSDIR}."
.endif
.if !defined(NOPORTEXAMPLES)
.for exdir in ${EXDIRS}
	@${MKDIR} ${EXAMPLESDIR}/${exdir}
	@${INSTALL_DATA} ${WRKSRC}/examples/${exdir}/* ${EXAMPLESDIR}/${exdir}
.endfor
	@${FIND} ${EXAMPLESDIR} \( -name "*.pl" -or -name "*.sh" \) -exec ${CHMOD} a+x {} \;
	@${ECHO_MSG} "===>  Examples installed in ${EXAMPLESDIR}."
.endif

.include <bsd.port.post.mk>
