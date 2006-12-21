# New ports collection makefile for:    nicmond
# Date created:		2003/05/23
# Whom:			Dan Pelleg <daniel+nicmond@pelleg.org>
#
# $FreeBSD$
#

PORTNAME=	nicmond
PORTVERSION=	1.1
CATEGORIES=	net
MASTER_SITES=	http://www.agt.ne.jp/~a-gota/programs/nicmond/ \
		http://www.cs.cmu.edu/~dpelleg/download/
MASTER_SITE_SUBDIR=	${PORTNAME}

PATCH_SITES=	http://www.cs.cmu.edu/~dpelleg/download/
PATCHFILES=	nicmond-doc-en-1.1.diff

MAINTAINER=	daniel+nicmond@pelleg.org
COMMENT=	Network interface monitor

DEPRECATED=	Disappeared from the internet
EXPIRATION_DATE=2007-02-01

MANLANG=	ja
MANCOMPRESSED=	yes
MAN5=		nicmond.conf.5
MAN8=		nicmond.8

post-install:
	@${CAT} ${PKGMESSAGE}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && \
		${INSTALL_DATA} README README.en ${DOCSDIR}
.endif

.include <bsd.port.mk>
