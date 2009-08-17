# New ports collection makefile for:	xmldiff
# Date created:		Sun Oct  9 10:33:37 EDT 2005
# Whom:			Paul Chvostek <paul+ports@it.ca>
#
# $FreeBSD$
#

PORTNAME=	xmldiff
PORTVERSION=	0.01
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://software.decisionsoft.com/software/ \
		http://www.it.ca/~paul/src/
DISTFILES=	xmldiff.pl

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Display meaningful differences between XML files

RUN_DEPENDS=	xmlprpr:${PORTSDIR}/textproc/xmlprpr

USE_PERL5=	yes
NO_BUILD=	yes
PLIST_FILES=	bin/xmldiff

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} -f ${_DISTDIR}/${_DISTFILES} ${WRKSRC}

post-patch:
	@${REINPLACE_CMD} -e '1s:/usr/bin/perl:${PERL}:' ${WRKSRC}/xmldiff.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/xmldiff.pl ${PREFIX}/bin/xmldiff

.include <bsd.port.mk>
