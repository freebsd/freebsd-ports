# ex:ts=8
# New ports collection makefile for:	integrit
# Date created:			Dec 30, 2000
# Whom:				Ying-Chieh Liao <ijliao@csie.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	integrit
PORTVERSION=	2.03.02
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/b/-beta/}

MAINTAINER=	ports@FreeBSD.org

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
ALL_TARGET=	${PORTNAME} aux

MAN1=	i-ls.1 i-viewdb.1 integrit.1

pre-configure:
	@${PERL} -pi -e "s:= gcc:?=  cc:g" ${WRKSRC}/Makefile.in
	@${PERL} -pi -e "s:/usr/bin/test:/bin/test:g" ${WRKSRC}/hashtbl/configure

.include <bsd.port.mk>
