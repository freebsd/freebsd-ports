# New ports collection makefile for:	print-n-times
# Date created:                		August 03 2004
# Whom:                        		Aaron Straup Cope
# $FreeBSD$

PORTNAME=	print-n-times
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://aaronland.info/xsl/string/print-n-times/

MAINTAINER=	ascope@cpan.org
COMMENT=	Print a string (n) times

NO_BUILD=	yes

do-install:
	@${ECHO} "Installing in ${PREFIX}/share/xsl/string/"
	@${MKDIR} ${PREFIX}/share/xsl/string
	@${CP} ${WRKSRC}/*.xsl ${PREFIX}/share/xsl/string/

.include <bsd.port.mk>
