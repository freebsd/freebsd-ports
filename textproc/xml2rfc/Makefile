# New ports collection makefile for: xml2rfc
# Date created:         8 July 2002
# Whom:                 jabley@automagic.org
#
# $FreeBSD$

PORTNAME=	xml2rfc
PORTVERSION=	1.13
CATEGORIES=	textproc tcl83
MASTER_SITES=	http://xml.resource.org/authoring/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jabley@automagic.org

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

.include <bsd.port.mk>
