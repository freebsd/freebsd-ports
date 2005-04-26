# ports collection makefile for:	gmat
# Date created:		31 December 2000
# Whom:			grog
#
# $FreeBSD$
#

PORTNAME=	gmat
PORTVERSION=	0.2.4c
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.ora.com/pub/gmat/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	O'Reilly's SGML formatting package

RUN_DEPENDS=	${LOCALBASE}/bin/nsgmls:${PORTSDIR}/textproc/sp		\
		${LOCALBASE}/bin/procmail:${PORTSDIR}/mail/procmail	\
		${LOCALBASE}/share/sgml/docbook/catalog:${PORTSDIR}/textproc/docbook \
		${LOCALBASE}/share/sgml/iso12083/book.dtd:${PORTSDIR}/textproc/iso12083 \
		gv:${PORTSDIR}/print/gv

USE_PERL5_BUILD=yes
USE_REINPLACE=	yes
REINPLACE_ARGS=	-i ""

WRKSRC=		${WRKDIR}/${PORTNAME}-0.2.4
MAKE_ARGS=	CC="${CC}" PRODROOT="${DATADIR}" SOELIMPATHNAME="/usr/bin/soelim"
SUB_FILES=	pkg-message
PORTDOCS=	README gmat.sgm

DTDVER?=	4.2	# docbook-xml version

post-patch:
	@${RM} ${WRKSRC}/src/crlf/crlf.o ${WRKSRC}/src/crlf/crlf ${WRKSRC}/bin/gmat.troff.orig

pre-build:
# Change the pathnames in CATALOG & BOOKFILES
.for RP in /usr/local/prod %%PRODROOT%%
	${REINPLACE_CMD} -e "s|${RP}/sgml/ISO_12083-1993/dtds|${LOCALBASE}/share/sgml/iso12083|" \
		-e "s|${RP}/sgml/Davenport/dtds|${LOCALBASE}/share/sgml/docbook|" \
		-e "s|${RP}/sgml/DocBook-XML/iso|${LOCALBASE}/share/xml/docbook/${DTDVER}/ent/iso|" \
		-e "s|${RP}/sgml/DocBook-XML|${LOCALBASE}/share/xml/docbook/${DTDVER}|" \
		-e "s|${RP}/sgml/DocBook|${LOCALBASE}/share/sgml/docbook|" \
		${WRKSRC}/test/CATALOG ${WRKSRC}/sgml/CATALOG
.endfor
.for FILE in BOOKFILES CATALOG
	${REINPLACE_CMD} -e "s|/usr/local/prod|${DATADIR}|" ${WRKSRC}/test/${FILE}
.endfor
.for FILE in checkaheads kern10sed kern10sed0 kern10sed1
	${CHMOD} a+x ${WRKSRC}/bin/${FILE}
.endfor
	${REINPLACE_CMD} -e "s|/usr/local|${PREFIX}|" ${WRKSRC}/Makefile

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/crlf
	(cd ${WRKSRC}; tar cf - test) | (cd ${DATADIR}; tar xvf -)
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DATADIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
