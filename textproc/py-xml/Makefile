# Ports collection Makefile for:	PyXML
# Date created:				04/17/1999
# Whom:					nectar@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=		xml
PORTVERSION= 		0.6.3
CATEGORIES=		textproc python
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}                     \
			http://www.python.org/sigs/xml-sig/files/      \
			ftp://ftp.cdrom.com/pub/python/www.python.org/sigs/xml-sig/files/ \
			ftp://unix.hensa.ac.uk/mirrors/ftp.python.org/pub/www.python.org/sigs/xml-sig/files/
MASTER_SITE_SUBDIR=	pyxml
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}
DISTNAME=		PyXML-${PORTVERSION}

MAINTAINER=		johann@egenetics.com

BUILD_DEPENDS=		${PYDISTUTILS}

USE_PYTHON=		yes
PLIST=			${WRKDIR}/PLIST

.include <bsd.port.pre.mk>

.if ${PYTHON_VERSION} == "python1.5"
PLIST_SUB+=		PACKAGE_DIR=xml
.else
PLIST_SUB+=		PACKAGE_DIR=_xmlplus
.endif
PLISTS=			${PKGDIR}/pkg-plist

.if !defined(NOPORTDOCS)
DOCDIR=			share/doc/py-xml
# Document files to be installed in ${DOCDIR}
DOCS1=			xml-howto.txt xml-ref.txt
# Document files to be installed in ${DOCDIR}/xmlproc
DOCS2=			artikler.css basicapi.gif cmdline.gif          \
			standard.css wxval.gif                         \
			xmlproc-catalog-doco.html xmlproc-doco.html    \
			xmlproc-dtd-doco.html xmlproc-license.html     \
			xmlproc.html xmlproc_cmdline.html              \
			xmlproc_dtdparser.html xmlproc_ns.html         \
			xmlproc_tut.html
# Document files to be installed in ${DOCDIR}/4DOM
DOCS3=			4DOM.web Extensions.api Extensions.html        \
			index.html
# Complete list of document files
DOCS=			${DOCS1} ${DOCS2:S|^|xmlproc/|}                \
			${DOCS3:S|^|4DOM/|}

# Command to install document file and simultaneously add filename
# to the packing list
INSTALL_DOC=		${INSTALL_DATA} ${WRKSRC}/doc/@DOC             \
			${PREFIX}/${DOCDIR}/@DOC &&                    \
			${ECHO} ${DOCDIR}/@DOC >> ${PLIST}
.endif

do-build:
	cd ${WRKSRC} && ${PYTHON_CMD} setup.py build

pre-install:
	${CAT} ${PLISTS} > ${PLIST}
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/${DOCDIR}
	${MKDIR} ${PREFIX}/${DOCDIR}/xmlproc
	${MKDIR} ${PREFIX}/${DOCDIR}/4DOM
.for doc in ${DOCS}
	${INSTALL_DOC:S|@DOC|${doc}|g}
.endfor
	${ECHO} @dirrm ${DOCDIR}/xmlproc >> ${PLIST}
	${ECHO} @dirrm ${DOCDIR}/4DOM >> ${PLIST}
	${ECHO} @dirrm ${DOCDIR} >> ${PLIST}
.endif

do-install:
	cd ${WRKSRC} && ${PYTHON_CMD} setup.py install

.include <bsd.port.post.mk>
