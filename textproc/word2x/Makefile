# New ports collection makefile for:	word2x
# Date created:		10 June 1998
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	word2x
PORTVERSION=	0.005
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converter from MS Word to text, HTML or LaTeX

USE_GETOPT_LONG=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN1=		word2x.1
PLIST_FILES=	bin/rtest2 bin/word2x

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502126
BROKEN=		"Does not compile with gcc 3.4.2"
.endif

.include <bsd.port.post.mk>
