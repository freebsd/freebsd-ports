# New ports collection makefile for:    xmlada
# Date created:        21 Feb 2002
# Whom:                aidan
#
# $FreeBSD$
#

PORTNAME=	xmlada
PORTVERSION=	0.7.1
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://libre.act-europe.fr/xmlada/
DISTNAME=	XmlAda-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	aidan@velvet.net
COMMENT=	An XML parsing library for Ada 95

BUILD_DEPENDS=	adagcc:${PORTSDIR}/lang/gnat

WRKSRC=		${WRKDIR}/xmlada-0.7.1
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/xml.info ${PREFIX}/info/xmlada.info
	install-info ${PREFIX}/info/xmlada.info ${PREFIX}/info/dir
.endif

.include <bsd.port.mk>
