# Created by: ijliao
# $FreeBSD$

PORTNAME=	eukleides
PORTVERSION=	1.5.4
CATEGORIES=	math
MASTER_SITES=	http://www.eukleides.org/files/

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	A Euclidean geometry drawing language

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libreadline.so:${PORTSDIR}/devel/readline
RUN_DEPENDS=	pstoedit:${PORTSDIR}/graphics/pstoedit

USE_TEX=	latex
USES=		bison gettext iconv gmake tar:bzip2

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
USE_TEX+=	pdftex:build
PORTDOCS=	de.pdf fr.pdf
INFO=		eukleides
.endif

.ifndef NOPORTEXAMPLES
PORTEXAMPLES=	greenwich.euk sundial.euk vonkoch.euk
.endif

post-patch:
	@${GREP} -lR "#!/bin/bash" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|#!/bin/bash|#!/bin/sh|g'
	@${GREP} -lR "ginstall-info" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|ginstall-info|install-info|g'
	@${GREP} -lR "%%[[:alpha:]]\+%%" ${WRKSRC} |${XARGS} ${REINPLACE_CMD} \
		 -e "s|%%PREFIX%%|${STAGEDIR}${PREFIX}|g" \
		 -e "s|%%LOCALBASE%%|${LOCALBASE}|g" \
		 -e "s|%%EXAMPLESDIR%%|${STAGEDIR}${EXAMPLESDIR}|g" \
		 -e "s|%%DOCSDIR%%|${STAGEDIR}${DOCSDIR}|g"
	@${GREP} -lFR "gcc" ${WRKSRC} |${XARGS} ${REINPLACE_CMD} \
		-e "s|gcc|${CC}|g"
.if defined(${PORT_OPTIONS:MDOCS})
	@${REINPLACE_CMD} -e '/^install:/ s/install_doc//g' \
		 -e '/^all:/ s/doc//g' ${WRKSRC}/Makefile
.endif

.ifdef NOPORTEXAMPLES
	@${REINPLACE_CMD} -e 's/install_exm$$//g' ${WRKSRC}/Makefile
.endif

pre-install:
.ifndef NOPORTEXAMPLES
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.endif

post-install:
	for i in euktoeps euktopdf euktotex; do \
		${RM} ${STAGEDIR}${PREFIX}/bin/$${i}.bak; \
	done

.include <bsd.port.mk>
