# New ports collection makefile for:	txt2tags
# Date created:		2002-12-20
# Whom:			Alan Eldridge <alane@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	txt2tags
PORTVERSION=	1.5
CATEGORIES=	textproc
MASTER_SITES=	http://txt2tags.sourceforge.net/src/
EXTRACT_SUFX=	.tgz

MAINTAINER=	sergei@FreeBSD.org
COMMENT=	Utility to turn simply formatted text into markup (e.g., HTML)

USE_PYTHON=	yes
NO_BUILD=	yes

DOCS=		ChangeLog.txt README.html README.txt RULES TODO userguide/*
CONTRIB=	contrib/* extras/*
EXAMPLES=	samples/*

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/txt2tags ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${CONTRIB} ${DATADIR}
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${EXAMPLES} ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
