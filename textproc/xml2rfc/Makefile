# New ports collection makefile for: xml2rfc
# Date created:         8 July 2002
# Whom:                 jabley@automagic.org
#
# $FreeBSD$

PORTNAME=	xml2rfc
PORTVERSION=	1.19
CATEGORIES=	textproc tcl83
MASTER_SITES=	http://xml.resource.org/authoring/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jabley@automagic.org
COMMENT=	A tool to create RFCs and related documents from XML, as per RFC2629

RUN_DEPENDS=	tclsh8.3:${PORTSDIR}/lang/tcl83

.if !defined(WITHOUT_X11)
RUN_DEPENDS+=	wish8.3:${PORTSDIR}/x11-toolkits/tk83
CATEGORIES+=	tk83
.endif

NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/xml2rfc.tcl ${PREFIX}/bin/xml2rfc
	${LN} ${PREFIX}/bin/xml2rfc ${PREFIX}/bin/xml2txt
	${LN} ${PREFIX}/bin/xml2rfc ${PREFIX}/bin/xml2html
	${LN} ${PREFIX}/bin/xml2rfc ${PREFIX}/bin/xml2nroff
	${MKDIR} ${PREFIX}/share/doc/xml2rfc
	for doc in README.html README.txt README.xml \
	    draft-mrose-writing-rfcs.html draft-mrose-writing-rfcs.txt \
	    rfc2629.dtd rfc2629.html rfc2629.txt rfc2629.xml rfc2629.xslt; \
	do ${INSTALL_DATA} ${WRKSRC}/$${doc} ${PREFIX}/share/doc/xml2rfc; \
	done
	${INSTALL_DATA} ${WRKSRC}/.xml2rfc.rc ${PREFIX}/share/doc/xml2rfc/dot.xml2rfc.rc

post-install:
	@${ECHO}
	@${ECHO} Have a look at http://xml.resource.org/ for how to get and
	@${ECHO} update bibliographic summaries of each RFC and Internet Draft.
	@${ECHO}

.include <bsd.port.mk>
