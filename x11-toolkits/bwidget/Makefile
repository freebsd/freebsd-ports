# New ports collection makefile for: 	bwidget
# Date created:				Jan 29, 2002
# Whom:					Alexander Kabaev <ak03@gte.com>
#
# $FreeBSD$
#

PORTNAME=	bwidget
PORTVERSION=	1.4.1
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	tcllib
DISTNAME=	BWidget-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.ORG

NO_BUILD=	yes

do-install:
	@$(MKDIR) ${PREFIX}/lib/bwidget
	${INSTALL_DATA} ${WRKSRC}/*.tcl ${PREFIX}/lib/bwidget
	${CP} -R ${WRKSRC}/lang ${PREFIX}/lib/bwidget
	${CP} -R ${WRKSRC}/images ${PREFIX}/lib/bwidget
.if !defined(NOPORTDOCS)
	@$(MKDIR) $(DOCSDIR)
	${INSTALL_DATA} ${WRKSRC}/BWman/*.htm* ${DOCSDIR}
.endif

.include <bsd.port.mk>
