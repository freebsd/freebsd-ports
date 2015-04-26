# Created by: ijliao
# $FreeBSD$

PORTNAME=	eukleides
PORTVERSION=	1.5.4
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	http://www.eukleides.org/files/

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Euclidean geometry drawing language

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libreadline.so:${PORTSDIR}/devel/readline
RUN_DEPENDS=	pstoedit:${PORTSDIR}/graphics/pstoedit

USE_TEX=	latex
USES=		bison gettext iconv gmake tar:bzip2
INSTALL_TARGET=	install PREFIX=${STAGEDIR}${PREFIX}

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
USES+=		makeinfo
USE_TEX+=	pdftex:build
INFO=		eukleides
.endif

PORTDOCS=	de.pdf fr.pdf
PORTEXAMPLES=	greenwich.euk sundial.euk vonkoch.euk

post-patch:
	@${GREP} -lR "#!/bin/bash" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|#!/bin/bash|#!/bin/sh|g'
	@${GREP} -lR "ginstall-info" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|ginstall-info|install-info|g'
	@${GREP} -lR "%%[[:alpha:]]\+%%" ${WRKSRC} |${XARGS} ${REINPLACE_CMD} \
		 -e "s|%%PREFIX%%|${PREFIX}|g" \
		 -e "s|%%LOCALBASE%%|${LOCALBASE}|g" \
		 -e "s|%%EXAMPLESDIR%%|\$${PREFIX}/${EXAMPLESDIR_REL}|g" \
		 -e "s|%%DOCSDIR%%|\$${PREFIX}/${DOCSDIR_REL}|g"
	@${GREP} -lFR "gcc" ${WRKSRC} |${XARGS} ${REINPLACE_CMD} \
		-e "s|gcc|${CC}|g"
.if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e '/^install:/ s/install_doc//g' \
		 -e '/^all:/ s/doc//g' ${WRKSRC}/Makefile
.endif

.if ! ${PORT_OPTIONS:MEXAMPLES}
	@${REINPLACE_CMD} -e 's/install_exm$$//g' ${WRKSRC}/Makefile
.endif

pre-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}

post-install:
	for i in euktoeps euktopdf euktotex; do \
		${RM} ${STAGEDIR}${PREFIX}/bin/$${i}.bak; \
	done

.include <bsd.port.mk>
