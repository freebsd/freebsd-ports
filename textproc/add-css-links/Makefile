# New ports collection makefile for:	add-css-links
# Date created:                		August 03 2004
# Whom:                        		Aaron Straup Cope
# $FreeBSD$

PORTNAME=	add-css-links
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://aaronland.info/xsl/xhtml/add-css-links/

MAINTAINER=	ascope@cpan.org
COMMENT=	Add one or more CSS <link> elements to an XHTML document

NO_BUILD=	yes

do-install:
	@${ECHO} "Installing in ${PREFIX}/share/xsl/xhtml/"
	@${MKDIR} ${PREFIX}/share/xsl/xhtml
	@${CP} ${WRKDIR}/xhtml/*.xsl ${PREFIX}/share/xsl/xhtml/

.include <bsd.port.mk>
