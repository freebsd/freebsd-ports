# New ports collection makefile for:	xmlprpr
# Date created:		Sun Oct  9 10:33:37 EDT 2005
# Whom:			Paul Chvostek <paul+ports@it.ca>
#
# $FreeBSD$
#

PORTNAME=	xmlprpr
PORTVERSION=	1.32
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://software.decisionsoft.com/software/ \
		http://www.it.ca/~paul/src/
DISTFILES=	xmlpp.pl

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An XML pretty printer

USE_PERL5=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
PLIST_FILES=	bin/xmlprpr

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} -f ${_DISTDIR}/${_DISTFILES} ${WRKSRC}

post-patch:
	@${REINPLACE_CMD} -e '1s:/usr/bin/perl:${PERL}:' ${WRKSRC}/xmlpp.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/xmlpp.pl ${PREFIX}/bin/xmlprpr

.include <bsd.port.mk>
