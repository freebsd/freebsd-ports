# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	bamg
PORTVERSION=	1.01
PORTREVISION=	1
CATEGORIES=	math science
MASTER_SITES=	http://www.ann.jussieu.fr/hecht/ftp/bamg/
DISTFILES=	${PORTNAME}-v${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Bidimensional Anisotropic Mesh Generator

RESTRICTED=	Contact author personally regarding commercial use

BROKEN=		Master site no longer exists

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_XORG=	x11
USES=		gmake shebangfix
SHEBANG_FILES=	examples/quadloop/dotest.pl
MAKE_JOBS_UNSAFE=	yes

ALL_TARGET=	world
INSTALL_TARGET=	install-world

BINS=		bamg bamg-g cvmsh2 drawbdmesh
EXDIRS=		NACA012 quadloop square test

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MDOCS}
DISTFILES+=	${PORTNAME}.pdf
EXTRACT_ONLY=	${PORTNAME}-v${PORTVERSION}${EXTRACT_SUFX}
.endif

.pre-configure:
HOSTTYPE=	${UNAME} -s
MAKE_ENV=	HOSTTYPE=${${HOSTTYPE}}

post-patch:
	@${MV} ${WRKSRC}/FLAG.linux ${WRKSRC}/FLAG.${${HOSTTYPE}}
	@${MV} ${WRKSRC}/FLAG.linux.orig ${WRKSRC}/FLAG.linux

post-install:
.for bin in ${BINS}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${bin}
.endfor
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${DISTDIR}/${PORTNAME}.pdf ${STAGEDIR}${DOCSDIR}
.endif
.for exdir in ${EXDIRS}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/${exdir}
	@${INSTALL_DATA} ${WRKSRC}/examples/${exdir}/* ${STAGEDIR}${EXAMPLESDIR}/${exdir}
.endfor
	@${FIND} ${STAGEDIR}${EXAMPLESDIR} \( -name "*.pl" -or -name "*.sh" \) -exec ${CHMOD} a+x {} \;

.include <bsd.port.post.mk>
