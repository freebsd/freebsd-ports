# Ports collection Makefile for:	PyXML
# Date created:				04/17/1999
# Whom:					nectar@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=		py-xml
PORTVERSION= 		0.5.4
CATEGORIES=		textproc python
MASTER_SITES=		http://www.python.org/sigs/xml-sig/files/      \
			ftp://ftp.cdrom.com/pub/python/www.python.org/sigs/xml-sig/files/ \
			ftp://ftp.kddlabs.co.jp/pub/lang/python/www.python.org/sigs/xml-sig/files/ \
			ftp://unix.hensa.ac.uk/mirrors/ftp.python.org/pub/www.python.org/sigs/xml-sig/files/
DISTNAME=		PyXML-${PORTVERSION}

MAINTAINER=		nectar@FreeBSD.org

BUILD_DEPENDS=		${LOCALBASE}/lib/python1.5/site-packages/distutils/core.py:${PORTSDIR}/misc/py-distutils
RUN_DEPENDS=		python:${PORTSDIR}/lang/python

PLIST=			${WRKDIR}/PLIST

.if !defined(NOPORTDOCS)
DOCDIR=			share/doc/py-xml
# Document files to be installed in ${DOCDIR}
DOCS1=			xml-howto.txt xml-ref.txt
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

do-build:
	cd ${WRKSRC} && python setup.py build

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

do-install:
	cd ${WRKSRC} && python setup.py install

.include <bsd.port.mk>
