# New ports collection makefile for:	XHTML DTD
# Date created:		10 May 2000
# Whom:			kuriyama
#
# $FreeBSD$
#

PORTNAME=	xhtml
PORTVERSION=	1.0
PORTRIVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.w3.org/TR/xhtml1/
DISTNAME=	xhtml1

MAINTAINER=	kuriyama@FreeBSD.org

BUILD_DEPENDS=	${MKCATALOG}:${PORTSDIR}/textproc/mkcatalog
RUN_DEPENDS=	${MKCATALOG}:${PORTSDIR}/textproc/mkcatalog

USE_ZIP=	YES
NO_MTREE=	YES
NO_BUILD=	YES
#WRKSRC=		${WRKDIR}/

INSTDIR=	${PREFIX}/share/xml
DTDDIR=		${INSTDIR}/dtd/xhtml
DTDFILES=	xhtml-lat1.ent xhtml-special.ent xhtml-symbol.ent \
		xhtml.soc xhtml1-frameset.dtd xhtml1-strict.dtd \
		xhtml1-transitional.dtd xhtml1.dcl
MKCATALOG=	${PREFIX}/sbin/mkcatalog
PLIST_SUB=	MKCATALOG=${MKCATALOG}

pre-install:
	@[ -d ${DTDDIR}	 ] || ${MKDIR} ${DTDDIR}

do-install:
	@(cd ${WRKSRC}/DTD; ${INSTALL_DATA} ${DTDFILES} ${DTDDIR})

post-install:
	@${MKCATALOG} -c ${INSTDIR}/catalog -q install dtd/xhtml xhtml.soc

.include <bsd.port.mk>
