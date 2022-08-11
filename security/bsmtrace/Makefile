PORTNAME=	bsmtrace
PORTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	LOCAL/csjp

MAINTAINER=	csjp@FreeBSD.org
COMMENT=	BSM based intrusion detection system

LICENSE=	BSD2CLAUSE

SUB_FILES=	pkg-message

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	PCRE EXAMPLES

PCRE_LIB_DEPENDS=	libpcre.so:devel/pcre
PCRE_MAKE_ENV=		PCRE=1
PCRE_USES=		localbase
PCRE_LIBS=		-lpcre

pre-build:
	${REINPLACE_CMD} -e \
		's,/etc/bsmtrace.conf,${PREFIX}/etc/bsmtrace.conf,' \
		${WRKSRC}/config.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin

	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.conf.5 \
		${STAGEDIR}${MAN5PREFIX}/man/man5

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
