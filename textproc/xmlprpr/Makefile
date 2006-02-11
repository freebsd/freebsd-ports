# New ports collection makefile for:	xmlprpr
# Date created:		Sun Oct  9 10:33:37 EDT 2005
# Whom:			Paul Chvostek <paul+ports@it.ca>
#
# $FreeBSD$
#

PORTNAME=	xmlprpr
PORTVERSION=	1.32
CATEGORIES=	textproc
MASTER_SITES=	http://software.decisionsoft.com/software/
DISTFILES=	xmlpp.pl
EXTRACT_ONLY=

MAINTAINER=	paul+ports@it.ca
COMMENT=	A XML pretty printer

USE_PERL5=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
PLIST_FILES=	bin/xmlprpr

do-install:
	${INSTALL_SCRIPT} ${_DISTDIR}/${_DISTFILES} ${PREFIX}/bin/xmlprpr

.include <bsd.port.mk>
