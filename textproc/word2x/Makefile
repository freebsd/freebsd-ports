# New ports collection makefile for:	word2x
# Date created:		10 June 1998
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	word2x
PORTVERSION=	0.005
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	word2x

MAINTAINER=	billf@FreeBSD.org
COMMENT=	Converter from MS Word to text, HTML or LaTeX

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN1=	word2x.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
BROKEN=         "Does not compile (bad C++ code)"
.endif

.include <bsd.port.post.mk>
