# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	cgic
PORTVERSION=	2.05
CATEGORIES=	www
MASTER_SITES=	http://www.boutell.com/cgic/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ANSI C library for CGI programming

DEPRECATED=	Unmaintained since 2000
EXPIRATION_DATE=	2014-04-11
MAKE_ENV=	SHLIB_MAJOR="${SHLIB_MAJOR}"
MAKEFILE=	${FILESDIR}/Makefile.lib
PLIST_SUB=	SHLIB_MAJOR="${SHLIB_MAJOR}"
USE_LDCONFIG=	yes
MAKE_ENV+=	WITHOUT_PROFILE=yes __MAKE_CONF=/dev/null SRCCONF=/dev/null

SHLIB_MAJOR=	${PORTVERSION:R}

NO_STAGE=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.txt ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/capture.c ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/cgictest.c ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
