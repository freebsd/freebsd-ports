# Created by: nbm
# $FreeBSD$

PORTNAME=	offlineimap
DISTVERSION=	6.5.5
CATEGORIES=	mail python
MASTER_SITES=	http://dist.codelabs.ru/fbsd/offlineimap/

PATCH_SITES=	http://codelabs.ru/patches/offlineimap/

MAINTAINER=	rea@FreeBSD.org
COMMENT=	Powerful IMAP/Maildir synchronization and reader support

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

LICENSE_FILE_GPLv2=${WRKSRC}/COPYING

OPTIONS_DEFINE=	HTMLDOCS EXAMPLES
HTMLDOCS_DESC=	Generate HTML documentation

WRKSRC?=	${WRKDIR}/${DISTNAME}
SUB_FILES=	pkg-message
PATCH_STRIP=	-p1

USE_GITHUB=	yes
GH_ACCOUNT=	OfflineIMAP
GH_TAGNAME=	v${DISTVERSION}
GH_COMMIT=	8bc2f35

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

DOC_FILES=	Changelog.maint.rst Changelog.rst \
		docs/INSTALL.rst docs/MANUAL.rst \
		docs/doc-src/API.rst docs/doc-src/FAQ.rst \
		docs/doc-src/HACKING.rst docs/doc-src/INSTALL.rst \
		docs/doc-src/MANUAL.rst docs/doc-src/advanced_config.rst \
		docs/doc-src/features.rst docs/doc-src/index.rst \
		docs/doc-src/nametrans.rst docs/doc-src/offlineimap.rst \
		docs/doc-src/repository.rst docs/doc-src/ui.rst
PORTDOCS=	docs ${DOC_FILES:N*/*}
EXAMPLE_FILES=	offlineimap.conf offlineimap.conf.minimal
PORTEXAMPLES=	${EXAMPLE_FILES:N*/*}

DOC_DIRS=	${DOC_FILES:H:O:u:N.}
EXAMPLE_DIRS=	${EXAMPLE_FILES:H:O:u:N.}

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS} && ${PORT_OPTIONS:MHTMLDOCS}
BUILD_DEPENDS+=	rst2html:${PORTSDIR}/textproc/py-docutils
DOC_FILES:=	${DOC_FILES} ${DOC_FILES:M*.rst:S/.rst$/.html/}
.endif

# This is needed for pkg-message.in
.if ${PORT_OPTIONS:MEXAMPLES}
SUB_LIST+=	PORTEXAMPLES=""
.else
SUB_LIST+=	PORTEXAMPLES="@comment "
.endif

post-build:
.if ${PORT_OPTIONS:MDOCS} && ${PORT_OPTIONS:MHTMLDOCS}
.for r in ${DOC_FILES:M*.rst}
	@${ECHO} "Translating ${r} to HTML..."
	@rst2html ${WRKSRC}/${r} ${WRKSRC}/${r:R}.html
.endfor
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@for i in ${DOC_DIRS}; do \
	  ${MKDIR} ${DOCSDIR}/$$i; \
	  done
	@cd ${WRKSRC} && for i in ${DOC_FILES}; do \
	  ${ECHO} "Installing ${DOCSDIR}/$$i"; \
	  ${INSTALL_DATA} $$i ${DOCSDIR}/$$i; \
	  done
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	@for i in ${EXAMPLE_DIRS}; do \
	  ${MKDIR} ${EXAMPLESDIR}/$$i; \
	  done
	@cd ${WRKSRC} && for i in ${EXAMPLE_FILES}; do \
	  ${ECHO} "Installing ${EXAMPLESDIR}/$$i"; \
	  ${INSTALL_DATA} $$i ${EXAMPLESDIR}/$$i; \
	  done
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
