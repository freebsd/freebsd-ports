# New ports collection makefile for:	libcgic
# Date created:				27 July 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	cgic
PORTVERSION=	2.05
CATEGORIES=	www
MASTER_SITES=	http://www.boutell.com/cgic/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ANSI C library for CGI programming

MAKE_ENV=	SHLIB_MAJOR="${SHLIB_MAJOR}"
MAKEFILE=	${FILESDIR}/Makefile.lib
PLIST_SUB=	SHLIB_MAJOR="${SHLIB_MAJOR}"
INSTALLS_SHLIB=	yes

SHLIB_MAJOR=	${PORTVERSION:R}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.txt ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/capture.c ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/cgictest.c ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
