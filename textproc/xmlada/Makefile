# New ports collection makefile for:    xmlada
# Date created:        21 Feb 2002
# Whom:                aidan
#
# $FreeBSD$
#

PORTNAME=	xmlada
PORTVERSION=	0.7.1
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	http://libre.act-europe.fr/xmlada/
DISTNAME=	XmlAda-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	aidan@velvet.net
COMMENT=	An XML parsing library for Ada 95

BUILD_DEPENDS=	adagcc:${PORTSDIR}/lang/gnat

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500039
WITHOUT_CPU_CFLAGS=	yes
.endif
WRKSRC=		${WRKDIR}/xmlada-0.7.1
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

INFO=		xmlada
PORTDOCS=	xml.html xml_1.html xml_2.html xml_3.html xml_4.html \
		xml_5.html xml_6.html xml_toc.html xml_ovr.html xml_abt.html

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.html ${DOCSDIR}
.endif
	${INSTALL_DATA} ${WRKSRC}/docs/xml.info ${PREFIX}/${INFO_PATH}/xmlada.info
	install-info ${PREFIX}/${INFO_PATH}/xmlada.info ${PREFIX}/${INFO_PATH}/dir

.include <bsd.port.post.mk>
