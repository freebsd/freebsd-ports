# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	liberator
PORTVERSION=	2.0.2
PORTREVISION=	1
CATEGORIES=	net-p2p
MASTER_SITES=	SF/${PORTNAME}/ofcp/ofcp-${PORTVERSION}
DISTNAME=	ofcp-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command line client to FreeNet Network

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:bzip2
USE_OCAML=	yes
USE_OCAML_CAMLP4=yes
ALL_TARGET=	all opt
MAKE_JOBS_UNSAFE=yes

DATA_FILES=	liber_mimetypes
DOC_FILES=	COPYING FREESITE-HOWTO README TODO
LIB_FILES=      fcp.cma hlfi.cma asfi.cma fcp.cmxa hlfi.cmxa asfi.cmxa \
		fcp.mli hlfreenet.mli asfreenet.mli fieldset.mli \
		fstream.mli \
		fcp.cmi hlfreenet.cmi asfreenet.cmi fieldset.cmi \
		fstream.cmi

OPTIONS_DEFINE=	DOCS

post-patch:
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|; \
		s|%%DATADIR%%|${DATADIR:S,^${PREFIX}/,,}|' \
		${FILESDIR}/wrapper.sh > ${WRKDIR}/wrapper.sh

do-configure:
	@${REINPLACE_CMD} -E \
		-e 's|^(PREFIX).*$$|\1=${PREFIX}|; \
			s|^(OCAML_PREFIX).*$$|\1=${PREFIX}/lib/ocaml|' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/liber ${STAGEDIR}${PREFIX}/bin/liber-real
	${INSTALL_SCRIPT} ${WRKDIR}/wrapper.sh ${STAGEDIR}${PREFIX}/bin/liber
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${DATA_FILES:S|^|${WRKSRC}/|} ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/ocaml
	${INSTALL_DATA} ${LIB_FILES:S|^|${WRKSRC}/|} \
		${STAGEDIR}${PREFIX}/lib/ocaml

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
