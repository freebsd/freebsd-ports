# New ports collection makefile for:	libident
# Date created:		9 October 1995
# Whom:			torstenb@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	libident
PORTVERSION=	0.32
CATEGORIES=	security
MASTER_SITES=	http://rdenisc.free.fr/libident/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A small library to interface the ident protocol server (rfc1413)

USE_GNOME=	gnometarget lthack
USE_LIBTOOL_VER=15
INSTALLS_SHLIB=	yes

MAN3=		ident.3

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in README
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
