# New ports collection makefile for:	V.E.R.A.
# Date created:		9 March 1999
# Whom:			Dima Sivachenko	<dima@chg.ru>
#
# $FreeBSD$
#

PORTNAME=	vera
PORTVERSION=	1.9
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	vera

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Virtual Entity of Relevant Acronyms

INFO=		vera

do-build:
	@ cd ${WRKSRC} && makeinfo --no-split vera.texi

do-install:
	@ ${INSTALL_DATA} ${WRKSRC}/vera.info ${PREFIX}/info

post-install:
	@ install-info ${PREFIX}/info/vera.info ${PREFIX}/info/dir

.include <bsd.port.mk>
