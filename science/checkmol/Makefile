PORTNAME=	checkmol
PORTVERSION=	0.5
PORTREVISION=	18
CATEGORIES=	science
MASTER_SITES=	https://homepage.univie.ac.at/norbert.haider/download/chemistry/checkmol/
DISTFILES=	${PORTNAME}
EXTRACT_SUFX=	.pas

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Analyze molecules for the presence of functional groups
WWW=		https://homepage.univie.ac.at/norbert.haider/cheminf/cmmm.html

LICENSE=	GPLv2+

ONLY_FOR_ARCHS=	aarch64 amd64 i386

NO_WRKSUBDIR=	yes

EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=	#
EXTRACT_AFTER_ARGS=	${WRKSRC}

USES=		fpc

PLIST_FILES=	bin/checkmol bin/matchmol

do-build:
	(cd ${WRKSRC} && ${LOCALBASE}/bin/fpc ${EXTRACT_ONLY} -S2 -O3)

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} ${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME})
	(cd ${STAGEDIR}${PREFIX}/bin && ${LN} ${PORTNAME} matchmol)

.include <bsd.port.mk>
