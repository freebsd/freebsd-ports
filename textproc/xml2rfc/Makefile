# New ports collection makefile for: xml2rfc
# Date created:         8 July 2002
# Whom:                 jabley@automagic.org
#
# $FreeBSD$

PORTNAME=	xml2rfc
PORTVERSION=	1.29
CATEGORIES=	textproc tcl83
MASTER_SITES=	http://xml.resource.org/authoring/
EXTRACT_SUFX=	.tgz

MAINTAINER=	lennox@cs.columbia.edu
COMMENT=	A tool to create RFCs and related documents from XML, as per RFC2629

RUN_DEPENDS=	tclsh8.3:${PORTSDIR}/lang/tcl83

.if !defined(WITHOUT_X11)
RUN_DEPENDS+=	wish8.3:${PORTSDIR}/x11-toolkits/tk83
CATEGORIES+=	tk83
.endif

NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/xml2rfc.tcl ${PREFIX}/bin/xml2rfc
	${LN} -f ${PREFIX}/bin/xml2rfc ${PREFIX}/bin/xml2txt
	${LN} -f ${PREFIX}/bin/xml2rfc ${PREFIX}/bin/xml2html
	${LN} -f ${PREFIX}/bin/xml2rfc ${PREFIX}/bin/xml2nroff
.if !defined (NOPORTDOCS)
	${MKDIR} ${DOCSDIR} ${DOCSDIR}/contrib
.for doc in LICENSE README.html README.txt README.xml \
	    draft-mrose-writing-rfcs.html draft-mrose-writing-rfcs.txt \
	    rfc2629.dtd rfc2629.html rfc2629.rnc rfc2629.txt rfc2629.xml \
	    rfc2629.xsd sample.html sample.txt sample.xml xml2rfc-win.png
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
	${INSTALL_DATA} ${WRKSRC}/contrib/${doc} ${DOCSDIR}/contrib
.endfor
	${INSTALL_DATA} ${WRKSRC}/.xml2rfc.rc ${DOCSDIR}/dot.xml2rfc.rc
.endif

post-install:
	@${ECHO}
	@${ECHO} Have a look at http://xml.resource.org/ for how to get and
	@${ECHO} update bibliographic summaries of each RFC and Internet Draft.
	@${ECHO}

.include <bsd.port.mk>
