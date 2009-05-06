# New ports collection makefile for:   amberfish
# Date created:			21 Aug 2008
# Whom:				Pedro Giffuni
#
# $FreeBSD$
#

PORTNAME=	amberfish
PORTVERSION=	1.6.4
CATEGORIES=	textproc databases
MASTER_SITES=	SF	\
		http://etymon.com/software/amberfish/stable/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	General purpose text retrieval Software

LIB_DEPENDS=	xerces-c.27:${PORTSDIR}/textproc/xerces-c2

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAN1=	af.1

post-extract:
	${INSTALL_DATA} ${FILESDIR}/porter.cc ${WRKSRC}/src

.if !defined(NOPORTDOCS)
post-build:
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} html)

post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/amberfish.png ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/html/*.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
