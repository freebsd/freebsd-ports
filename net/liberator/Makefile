# New ports collection makefile for:	liberator
# Date created:				Fri May 2 04:23:24 UTC 2003
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	liberator
PORTVERSION=	2.0.2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	ofcp-${PORTVERSION}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Command line client to FreeNet Network 

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml

USE_BZIP2=	yes
USE_REINPLACE=	yes
ALL_TARGET=	all opt

DATA_FILES=	liber_mimetypes
DOC_FILES=	COPYING FREESITE-HOWTO README TODO
LIB_FILES=      fcp.cma hlfi.cma asfi.cma fcp.cmxa hlfi.cmxa asfi.cmxa \
		fcp.mli hlfreenet.mli asfreenet.mli fieldset.mli \
		fstream.mli \
		fcp.cmi hlfreenet.cmi asfreenet.cmi fieldset.cmi \
		fstream.cmi

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
# bin
	@${INSTALL_PROGRAM} ${WRKSRC}/liber ${PREFIX}/bin/liber-real
	@${INSTALL_SCRIPT} ${WRKDIR}/wrapper.sh ${PREFIX}/bin/liber
# data
	@${MKDIR} ${DATADIR}
.for file in ${DATA_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DATADIR}
.endfor
# doc
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
.for file in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif
# lib
	@${MKDIR} ${PREFIX}/lib/ocaml
.for file in ${LIB_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/lib/ocaml
.endfor

.include <bsd.port.mk>
