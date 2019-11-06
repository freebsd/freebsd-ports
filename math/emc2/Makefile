# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	emc2
DISTVERSIONPREFIX=v
DISTVERSION=	2.17
CATEGORIES=	math science
MASTER_SITES=	https://www.ljll.math.upmc.fr/~hecht/ftp/emc2/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical editor of two-dimensional mesh geometries

LICENSE=	INRIA
LICENSE_NAME=	INRIA license, perhaps specific to emc2
LICENSE_FILE=	${WRKSRC}/COPYRIGHT
LICENSE_PERMS=	auto-accept no-dist-sell no-pkg-sell

USES=		gmake xorg
USE_XORG=	x11 xau xcb xdmcp

ALL_TARGET=	${PORTNAME}
RESTRICTED=	No resale, contact author for commercial usage

.if defined(LANG) && ${LANG:Mfr*} != ""
CFLAGS+=	-DFRENCH
.endif

PORTDOCS=	${DISTFILES:M*.pdf}
PORTEXAMPLES=	*

PLIST_FILES=	bin/emc2 bin/prf_f3d

OPTIONS_DEFINE=	DOCS EXAMPLES

DOCS_DISTFILES=	RTemc2_fr.pdf RTemc2_gb.pdf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/emc2 ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/prf_f3d ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${DISTDIR} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
