# Created by: alm
# $FreeBSD$

PORTNAME=	bsmtrace
PORTVERSION=	1.4
PORTREVISION=	0
CATEGORIES=	security
MASTER_SITES=	LOCAL/csjp

MAINTAINER=	alm@FreeBSD.org
COMMENT=	BSM based intrusion detection system

SUB_FILES=	pkg-message

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	PCRE EXAMPLES

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPCRE}
LIB_DEPENDS=	libpcre.so:devel/pcre
MAKE_ENV+=	PCRE=1
CFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lpcre
.endif

pre-build:
	${REINPLACE_CMD} -e \
		's,/etc/bsmtrace.conf,${PREFIX}/etc/bsmtrace.conf,' \
		${WRKSRC}/config.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.conf.5 \
		${STAGEDIR}${MAN5PREFIX}/man/man5

.include <bsd.port.mk>
