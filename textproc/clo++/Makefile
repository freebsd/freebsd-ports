# New ports collection makefile for:	clo++
# Date created:				30 January 2001
# Whom:					Kevin Lo <kevlo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	clo++
PORTVERSION=	0.3.0
CATEGORIES=	textproc
MASTER_SITES=	http://pmade.org/~pjones/software/clo++/download/

MAINTAINER=	kevlo@FreeBSD.org

LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2

GNU_CONFIGURE=	yes
CONFIGURE_ENV= CXXFLAGS="-I${LOCALBASE}/include"

post-install:
	@${MKDIR} ${PREFIX}/share/doc/clo++
	${INSTALL_DATA} ${WRKSRC}/doc/handbook.html ${PREFIX}/share/doc/clo++

.include <bsd.port.mk>
