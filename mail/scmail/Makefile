# New ports collection makefile for:	scmail
# Date created:				13 April 2003
# Whom:					Kimura Fuyuki <fuyuki@hadaly.org>
#
# $FreeBSD$
#

PORTNAME=	scmail
PORTVERSION=	0.2
CATEGORIES=	mail
MASTER_SITES=	http://www.namazu.org/~satoru/scmail/

MAINTAINER=	fuyuki@nigredo.org
COMMENT=	A mail filter written in Scheme

BUILD_DEPENDS=	gosh:${PORTSDIR}/lang/gauche
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_REINPLACE=	yes
MAKE_ARGS=	PREFIX="${PREFIX}" DATADIR="${EXAMPLESDIR}"

post-patch:
	${REINPLACE_CMD} -e "s|cp -p|${CP}|g" ${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
