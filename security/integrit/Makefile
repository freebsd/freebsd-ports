# New ports collection makefile for:   integrit
# Date created:                Dec 30, 2000
# Whom:                        Ying-Chieh Liao <ijliao@csie.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	integrit
PORTVERSION=	1.04.03b
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/b/-beta/}

MAINTAINER=		ijliao@FreeBSD.org

WRKSRC=			${WRKDIR}/integrit-1.04

GNU_CONFIGURE=	yes

USE_OPENSSL=	yes
USE_GMAKE=		yes
ALL_TARGET=		${PORTNAME} aux

MAN1=			integrit.1

pre-configure:
	${PERL} -pi -e "s:= gcc:?=  cc:g" ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
