# New ports collection makefile for: 	bwidget
# Date created:				Jan 29, 2002
# Whom:					Alexander Kabaev <ak03@gte.com>
#
# $FreeBSD$
#

PORTNAME=	bwidget
PORTVERSION=	1.8.0
PORTREVISION=	2
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF/tcllib/BWidget/${PORTVERSION}
DISTNAME=	BWidget-${PORTVERSION}

MAINTAINER=	mm@FreeBSD.org
COMMENT=	A high-level widget set for Tcl/Tk

USE_TK_RUN=	84+

NO_BUILD=	yes

do-install:
	@$(MKDIR) ${PREFIX}/lib/bwidget
	${INSTALL_DATA} ${WRKSRC}/*.tcl ${PREFIX}/lib/bwidget
	${TAR} -C ${WRKSRC} -cf - images lang | \
		${TAR} -C ${PREFIX}/lib/bwidget --unlink -xf -
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/lib/bwidget
.if !defined(NOPORTDOCS)
	@$(MKDIR) ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/BWman/*.htm* ${DOCSDIR}
.endif

.include <bsd.port.mk>
