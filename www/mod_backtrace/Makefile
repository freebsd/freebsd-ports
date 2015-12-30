# Created by: Frank Wall <fw@moov.de>
# $FreeBSD$

PORTNAME=	mod_backtrace
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://people.apache.org/~trawick/ \
		http://dl.moov.de/freebsd/${PORTNAME}/
DISTNAME=	${PORTNAME}.c
EXTRACT_SUFX=	# none
EXTRACT_ONLY=	# empty

MAINTAINER=	fw@moov.de
COMMENT=	Collects backtraces when a child process crashes

LICENSE=	APACHE20

MANUAL_PACKAGE_BUILD=	requires apache WITH_EXCEPTION_HOOK=yes

USES=		execinfo
USE_APACHE=	22+
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes
AP_EXTRAS+=	-lexecinfo
AP_LIB+=	${LOCALBASE}/lib
SHORTMODNAME=	backtrace

WRKSRC=		${WRKDIR}

pre-everything::
	@${ECHO_MSG} "*********************** PLEASE NOTE! ***********************"
	@${ECHO_MSG} "Apache httpd must be built with the --enable-exception-hook"
	@${ECHO_MSG} "configure option and mod_so enabled."
	@${ECHO_MSG} "*********************** PLEASE NOTE! ***********************"

do-extract:
	@${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/${PORTNAME}.c ${WRKSRC}

.include <bsd.port.mk>
