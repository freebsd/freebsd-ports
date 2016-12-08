# Created by: Frank Wall <fw@moov.de>
# $FreeBSD$

PORTNAME=	mod_whatkilledus
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://people.apache.org/~trawick/ \
		http://dl.moov.de/freebsd/${PORTNAME}/
DISTFILES=	mod_whatkilledus.c test_char.h
EXTRACT_ONLY=	# empty

MAINTAINER=	fw@moov.de
COMMENT=	Logs a report when a child process crashes

LICENSE=	APACHE20

MANUAL_PACKAGE_BUILD=	requires apache WITH_EXCEPTION_HOOK=yes

USE_APACHE=	22
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes
SHORTMODNAME=	whatkilledus

WRKSRC=		${WRKDIR}

do-extract:
	@${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/mod_whatkilledus.c ${WRKSRC}
	${CP} ${DISTDIR}/test_char.h ${WRKSRC}

pre-build:
	@${ECHO_MSG} "*********************** PLEASE NOTE! ***********************"
	@${ECHO_MSG} "Apache httpd must be built with the --enable-exception-hook"
	@${ECHO_MSG} "configure option and mod_so enabled."
	@${ECHO_MSG} "*********************** PLEASE NOTE! ***********************"

.include <bsd.port.mk>
