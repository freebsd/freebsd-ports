# ports collection makefile for:	gmat
# Date created:		31 December 2000
# Whom:			grog
#
# $FreeBSD$
#

PORTNAME=	gmat
PORTVERSION=	0.2.4b
PORTREVISION=	1
WRKSRC=		${WRKDIR}/${PORTNAME}-0.2.4
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.ora.com/pub/gmat/

MAINTAINER=	grog@FreeBSD.Org

RUN_DEPENDS=	${LOCALBASE}/bin/nsgmls:${PORTSDIR}/textproc/sp		\
		${LOCALBASE}/bin/procmail:${PORTSDIR}/mail/procmail	\
		${LOCALBASE}/share/sgml/docbook/3.1/docbook.dtd:${PORTSDIR}/textproc/docbook-310 \
		ghostview:${PORTSDIR}/print/ghostview

post-install:
	(cd ${WRKSRC}; tar cf - test) | (cd ${LOCALBASE}/share/gmat; tar xvf -)
# Change the pathnames in CATALOG
	(cd ${WRKSRC}/test; \
		sed < CATALOG "s:/usr/local/prod/sgml/DocBook:${LOCALBASE}/share/sgml/docbook:g; \
		s:/usr/local/prod:${LOCALBASE}/share/gmat:g" \
		> ${LOCALBASE}/share/gmat/test/CATALOG )
		
.include <bsd.port.mk>
