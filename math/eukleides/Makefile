# ex:ts=8
# Ports collection makefile for:	eukleides
# Date created:			Jun 4, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	eukleides
PORTVERSION=	1.5.3
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	http://www.eukleides.org/files/

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	A Euclidean geometry drawing language

LIB_DEPENDS=	readline.6:${PORTSDIR}/devel/readline
RUN_DEPENDS=	pstoedit:${PORTSDIR}/graphics/pstoedit \
		epstopdf:${PORTSDIR}/print/teTeX-base

USE_BZIP2=	yes
USE_BISON=	build
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_ICONV=	yes

MAN1=		eukleides.1 euktoeps.1 euktopdf.1 euktopst.1 euktotex.1

.ifndef NOPORTDOCS
BUILD_DEPENDS=	pdflatex:${PORTSDIR}/print/teTeX-base
PORTDOCS=	de.pdf fr.pdf
INFO=		eukleides
.endif

.ifndef NOPORTEXAMPLES
PORTEXAMPLES=	greenwich.euk sundial.euk vonkoch.euk
.endif

post-patch:
	${GREP} -lR "#!/bin/bash" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|#!/bin/bash|#!/bin/sh|g'
	${GREP} -lR "ginstall-info" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|ginstall-info|install-info|g'
	${GREP} -lR "%%[[:alpha:]]\+%%" ${WRKSRC} |${XARGS} ${REINPLACE_CMD} \
		 -e "s|%%PREFIX%%|${PREFIX}|g" \
		 -e "s|%%LOCALBASE%%|${LOCALBASE}|g" \
		 -e "s|%%EXAMPLESDIR%%|${EXAMPLESDIR}|g" \
		 -e "s|%%DOCSDIR%%|${DOCSDIR}|g"
.ifdef NOPORTDOCS
	${REINPLACE_CMD} -e '/^install:/ s/install_doc//g' \
		 -e '/^all:/ s/doc//g' ${WRKSRC}/Makefile
.endif

.ifdef NOPORTEXAMPLES
	${REINPLACE_CMD} -e 's/install_exm$$//g' ${WRKSRC}/Makefile
.endif

pre-install:
.ifndef NOPORTEXAMPLES
	${MKDIR} ${EXAMPLESDIR}
.endif

post-install:
	for i in euktoeps euktopdf euktotex; do \
		${RM} ${PREFIX}/bin/$${i}.bak; \
	done

.include <bsd.port.mk>
