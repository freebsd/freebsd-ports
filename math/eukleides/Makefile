# Created by: ijliao

PORTNAME=	eukleides
PORTVERSION=	1.5.4
PORTREVISION=	6
CATEGORIES=	math
MASTER_SITES=	http://www.eukleides.org/files/

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Euclidean geometry drawing language

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	pstoedit:graphics/pstoedit \
		getopt>=0:misc/getopt

USES=		bison gettext iconv gmake readline tar:bzip2
USE_TEX=	latex
INSTALL_TARGET=	install PREFIX=${STAGEDIR}${PREFIX}

# Fix build with clang11
CFLAGS+=	-fcommon

PORTDOCS=	de.pdf fr.pdf
PORTEXAMPLES=	greenwich.euk sundial.euk vonkoch.euk

OPTIONS_DEFINE=	DOCS EXAMPLES

DOCS_USES=	makeinfo
DOCS_USE=	TEX=pdftex:build
DOCS_INFO=	eukleides

post-patch:
	@${GREP} -lR "#!/bin/bash" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|#!/bin/bash|#!/bin/sh|g'
	@${GREP} -lR "ginstall-info" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|ginstall-info|install-info|g'
	@${EGREP} -lR "%%[[:alpha:]]+%%" ${WRKSRC} |${XARGS} ${REINPLACE_CMD} \
		 -e "s|%%PREFIX%%|${PREFIX}|g" \
		 -e "s|%%LOCALBASE%%|${LOCALBASE}|g" \
		 -e "s|%%EXAMPLESDIR%%|\$${PREFIX}/${EXAMPLESDIR_REL}|g" \
		 -e "s|%%DOCSDIR%%|\$${PREFIX}/${DOCSDIR_REL}|g" \
		 -e "s|%%CFLAGS%%|${CFLAGS}|g"
	@${GREP} -lFR "gcc" ${WRKSRC} |${XARGS} ${REINPLACE_CMD} \
		-e "s|gcc|${CC}|g"

post-patch-DOCS-off:
	@${REINPLACE_CMD} -e '/^install:/ s/install_doc//g' \
		 -e '/^all:/ s/doc//g' ${WRKSRC}/Makefile

post-patch-EXAMPLES-off:
	@${REINPLACE_CMD} -e 's/install_exm$$//g' ${WRKSRC}/Makefile

pre-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/bin/*.bak*

.include <bsd.port.mk>
