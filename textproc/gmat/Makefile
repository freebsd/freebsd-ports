# ports collection makefile for:	gmat
# Date created:		31 December 2000
# Whom:			grog
#
# $FreeBSD$
#

PORTNAME=	gmat
PORTVERSION=	0.2.4c
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.ora.com/pub/gmat/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	O'Reilly's SGML formatting package

RUN_DEPENDS=	${LOCALBASE}/bin/nsgmls:${PORTSDIR}/textproc/sp		\
		${LOCALBASE}/bin/procmail:${PORTSDIR}/mail/procmail	\
		${LOCALBASE}/share/sgml/docbook/3.1/docbook.dtd:${PORTSDIR}/textproc/docbook-310 \
		gv:${PORTSDIR}/print/gv

USE_PERL5_BUILD=yes
USE_REINPLACE=	yes
REINPLACE_ARGS=	-i ""

WRKSRC=		${WRKDIR}/${PORTNAME}-0.2.4
PKGMESSAGE=	${WRKDIR}/pkg-message
PORTDOCS=	README gmat.sgm

post-patch:
	@${RM} ${WRKSRC}/src/crlf/crlf.o ${WRKSRC}/src/crlf/crlf

pre-build:
# Change the pathnames in CATALOG & BOOKFILES
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
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif
	@${SED} -e "s|/usr/local|${PREFIX}|" < ${FILESDIR}/pkg-message.in	\
		> ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
