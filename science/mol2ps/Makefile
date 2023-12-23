PORTNAME=	mol2ps
PORTVERSION=	0.4b
PORTREVISION=	13
CATEGORIES=	science
MASTER_SITES=	https://homepage.univie.ac.at/norbert.haider/download/chemistry/mol2ps/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.pas
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Read molecular structure files and generate Postscript output
WWW=		https://homepage.univie.ac.at/norbert.haider/cheminf/mol2ps.html

LICENSE=	GPLv2+

NO_WRKSUBDIR=	yes

EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=	#
EXTRACT_AFTER_ARGS=	${WRKSRC}

USES=		fpc
USE_FPC=	rtl-objpas

PLIST_FILES=	bin/mol2eps bin/mol2ps bin/mol2svg %%DATADIR%%/color.conf

do-build:
	(cd ${WRKSRC} && ${LOCALBASE}/bin/fpc mol2ps -S2 -O3)

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} mol2ps ${STAGEDIR}${PREFIX}/bin)
	(cd ${STAGEDIR}${PREFIX}/bin && \
		${LN} mol2ps mol2eps && ${LN} mol2ps mol2svg)
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${FILESDIR} && ${INSTALL_DATA} color.conf ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
