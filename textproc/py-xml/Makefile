# Ports collection Makefile for:	PyXML
# Version required:			0.5.1
# Date created:				04/17/1999
# Whom:					nectar@FreeBSD.ORG
#
# $Id: Makefile,v 1.4 1998/11/14 09:43:26 asami Exp $
#

DISTNAME=		xml-0.5.1
PKGNAME=		py-xml-0.5.1
CATEGORIES=		textproc
MASTER_SITES=		http://www.python.org/sigs/xml-sig/files/
EXTRACT_SUFX=		.tgz

MAINTAINER=		nectar@FreeBSD.ORG

PLIST=			${WRKDIR}/PLIST

.if !defined(NOPORTDOCS)
DOCDIR=			share/doc/py-xml
# Document files to be installed in ${DOCDIR}
DOCS1=			index.html indices.html pythondoc.css          \
			xml-howto.txt xml-ref.txt                      \
			xml.arch.xmlarch.ArchDocHandler.html           \
			xml.arch.xmlarch.ArchException.html            \
			xml.arch.xmlarch.ArchParseState.html           \
			xml.arch.xmlarch.Architecture.html             \
			xml.arch.xmlarch.AttributeParser.html          \
			xml.arch.xmlarch.EventTracker.html             \
			xml.arch.xmlarch.Prettifier.html               \
			xml.arch.xmlarch.html
# Document files to be installed in ${DOCDIR}/xmlproc
DOCS2=			artikler.css basicapi.gif cmdline.gif          \
			standard.css xmlproc-catalog-doco.html         \
			xmlproc-doco.html xmlproc-dtd-doco.html        \
			xmlproc.html xmlproc_cmdline.html              \
			xmlproc_dtdparser.html xmlproc_ns.html         \
			xmlproc_tut.html
# Complete list of document files
DOCS=			${DOCS1} ${DOCS2:S|^|xmlproc/|}

# Command to install document file and simultaneously add filename
# to the packing list
INSTALL_DOC=		${INSTALL_DATA} ${WRKSRC}/doc/@DOC             \
			${PREFIX}/${DOCDIR}/@DOC &&                    \
			${ECHO} ${DOCDIR}/@DOC >> ${PLIST}
.endif

do-configure:
	cd ${WRKSRC} && ${MAKE} -f Makefile.pre.in boot

pre-install:
	${CP} ${PKGDIR}/PLIST ${PLIST}
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/${DOCDIR}
	${MKDIR} ${PREFIX}/${DOCDIR}/xmlproc
.for doc in ${DOCS}
	${INSTALL_DOC:S|@DOC|${doc}|g}
.endfor
	${ECHO} @dirrm ${DOCDIR}/xmlproc >> ${PLIST}
	${ECHO} @dirrm ${DOCDIR} >> ${PLIST}
.endif

.include <bsd.port.mk>
