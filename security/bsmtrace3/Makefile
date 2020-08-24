# $FreeBSD$

PORTNAME=	bsmtrace
PORTVERSION=	3.1
DISTVERSIONPREFIX=	v
CATEGORIES=	security
PKGNAMESUFFIX=	3

MAINTAINER=	csjp@FreeBSD.org
COMMENT=	BSM based intrusion detection system

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libpcre.so:devel/pcre

CONFLICTS_INSTALL=	bsmtrace-[0-9]*

USE_GITHUB=	yes
GH_ACCOUNT=	openbsm

SUB_FILES=	pkg-message

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	EXAMPLES

pre-build:
	${REINPLACE_CMD} -e \
		's,/etc/bsmtrace.conf,${PREFIX}/etc/bsmtrace.conf,' \
		${WRKSRC}/config.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin

	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 \
	    ${STAGEDIR}${MAN1PREFIX}/share/man/man1
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.conf.5 \
		${STAGEDIR}${MAN5PREFIX}/share/man/man5

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
