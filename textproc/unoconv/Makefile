# $FreeBSD$

PORTNAME=	unoconv
PORTVERSION=	0.6
CATEGORIES=	textproc python
MASTER_SITES=	http://dag.wieers.com/home-made/unoconv/
DIST_SUBDIR=	python

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Convert any document from and to any LibreOffice supported format

LICENSE=	GPLv2

RUN_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt

USE_PYTHON=	yes
NO_BUILD=	yes

PORTDATA=	 *

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	AUTHORS ChangeLog README.asciidoc WISHLIST

DOCSRCDIR2=	${WRKSRC}/doc
DOCSDIR2=	${DOCSDIR}/doc
DOC_FILES2=	errcode.txt filters.txt formats.txt office-installations.txt \
		selinux.txt unoconv.1.txt

MAN1=		${PORTNAME}.1

SUB_FILES=	${PORTNAME} pkg-message

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-install:
# Scripts
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin

# Executable
	${MKDIR} ${DATADIR}/tests
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${DATADIR}

# Data
.for f in *.odt *.csv
	@(cd ${WRKSRC}/tests && ${INSTALL_DATA} ${f} ${DATADIR}/tests)
.endfor

# Pixmaps
	${INSTALL_DATA} ${WRKSRC}/tests/dag.gif ${PREFIX}/share/pixmaps/${PORTNAME}.gif

# Documentation
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${DOCSDIR}
	${MKDIR} ${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${DOCSDIR2}
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 ${MAN1PREFIX}/man/man1
.endif

# pkg-message
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.mk>
