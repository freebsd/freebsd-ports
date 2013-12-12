# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	emc2
DISTVERSIONPREFIX=v
DISTVERSION=	2.16c
CATEGORIES=	math science
MASTER_SITES=	http://www.ann.jussieu.fr/~hecht/ftp/emc2/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
.if !defined(NOPORTDOCS)
DISTFILES+=	RTemc2_fr.pdf RTemc2_gb.pdf
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
.endif

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical editor of two-dimensional mesh geometries

LICENSE=	INRIA
LICENSE_NAME=	INRIA license, perhaps specific to emc2
LICENSE_FILE=	${WRKSRC}/COPYRIGHT
LICENSE_PERMS=	auto-accept no-dist-sell no-pkg-sell
RESTRICTED=	No resale, contact author for commercial usage

USE_XORG=	x11
USES=		gmake
ALL_TARGET=	${PORTNAME}

.if defined(LANG) && ${LANG:Mfr*} != ""
CFLAGS+=	-DFRENCH
.endif

PORTDOCS=	${DISTFILES:M*.pdf}
PORTEXAMPLES=	*

PLIST_FILES=	bin/emc2 bin/prf_f3d

NO_STAGE=	yes
.include <bsd.port.options.mk>
do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/emc2 ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/prf_f3d ${PREFIX}/bin

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@(cd ${DISTDIR} && ${INSTALL_MAN} ${PORTDOCS} ${DOCSDIR})
.endif
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}

.include <bsd.port.mk>
