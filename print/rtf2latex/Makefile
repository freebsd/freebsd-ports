# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rtf2latex
PORTVERSION=	1.5
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	support/rtf2latex
DISTNAME=	rtf2LaTeX.${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A filter that converts RTF (MS Rich Text Format) into LaTeX

DEPRECATED=	Unmaintained since 1999
EXPIRATION_DATE=	2014-04-10
WRKSRC=		${WRKDIR}/rtf2LaTeX

MAN1=		rtf2LaTeX.1

NO_STAGE=	yes
post-extract:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include <bsd.port.mk>
