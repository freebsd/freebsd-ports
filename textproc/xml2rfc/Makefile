# New ports collection makefile for:	xml2rfc
# Date created:				8 July 2002
# Whom:					jabley@automagic.org
#
# $FreeBSD$

PORTNAME=	xml2rfc
PORTVERSION=	1.35
CATEGORIES=	textproc
MASTER_SITES=	http://xml.resource.org/authoring/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tool to create RFCs and related documents from XML, as per RFC2629

USE_TCL_RUN=	yes

.if !defined(WITHOUT_X11)
USE_TK_RUN=	yes
.endif

PATCH_TCL_SCRIPTS=xml2rfc.tcl

NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/xml2rfc.tcl ${PREFIX}/bin/xml2rfc
	${LN} -f ${PREFIX}/bin/xml2rfc ${PREFIX}/bin/xml2txt
	${LN} -f ${PREFIX}/bin/xml2rfc ${PREFIX}/bin/xml2html
	${LN} -f ${PREFIX}/bin/xml2rfc ${PREFIX}/bin/xml2nroff
.if !defined (NOPORTDOCS)
	${MKDIR} ${DOCSDIR} ${DOCSDIR}/contrib ${DOCSDIR}/samples \
		${DOCSDIR}/contrib/alex.rousskov ${DOCSDIR}/contrib/fred.baker \
		${DOCSDIR}/contrib/pekka.savola ${DOCSDIR}/contrib/rob.austein
.for doc in LICENSE README.html README.txt README.xml \
	draft-mrose-writing-rfcs.html draft-mrose-writing-rfcs.txt \
	example.html example.txt example.xml rfc2629-other.ent \
	rfc2629-xhtml.ent rfc2629.dtd rfc2629.html rfc2629.rnc rfc2629.rng \
	rfc2629.xml rfc2629.xsd test.txt test.xml xml.xsd xml2rfc-win.png \
	xml2sgml.tcl
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.for doc in \
	alex.rousskov/xml2rfcpp.pl \
	fred.baker/new-draft.xml \
	pekka.savola/template.xml \
	pekka.savola/template0.xml \
	pekka.savola/template1b.xml \
	rob.austein/concat.pl \
	rob.austein/fast-sync.sh
	${INSTALL_DATA} ${WRKSRC}/contrib/${doc} ${DOCSDIR}/contrib/${doc}
.endfor
	for doc in ${WRKSRC}/samples/* ; do \
		${INSTALL_DATA} $${doc} ${DOCSDIR}/samples ; \
	done
	${INSTALL_DATA} ${WRKSRC}/.xml2rfc.rc ${DOCSDIR}/dot.xml2rfc.rc
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
