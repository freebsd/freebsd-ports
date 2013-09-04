# $FreeBSD$

PORTNAME=	packetdrill
PORTVERSION=	0.0.20130626
CATEGORIES=	net ipv6
MASTER_SITES=	LOCAL/hrs
DISTNAME=	${PORTNAME}-77954df72a78

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Network stack testing tool

LICENSE=	GPLv2

USES=		bison
MAKE_ENV+=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"
PORTDOCS=	README
PORTEXAMPLES=	fr-4pkt-sack-bsd.pkt fr-4pkt-sack-linux.pkt

OPTIONS_DEFINE=	DOCS EXAMPLES
OPTIONS_DEFAULT=DOCS EXAMPLES

.include <bsd.port.options.mk>

do-configure:
	${PRINTF} "%s\n" "#include <stdio.h>" "int main(void) {" \
	    "char *p = fmemopen; char *q = open_memstream; return 0; }" \
	    > ${WRKDIR}/configure.c
	${TOUCH} ${WRKSRC}/ports_config.h
	cd ${WRKDIR} && \
	    if ${CC} -o /dev/null configure.c > /dev/null 2>&1; then \
		${PRINTF} "%s\n" "#define HAVE_FMEMOPEN 1" \
		"#define HAVE_OPEN_MEMSTREAM 1" > ${WRKSRC}/ports_config.h; \
	    fi

pre-build:
	${INSTALL_DATA} ${FILESDIR}/Makefile ${FILESDIR}/Makefile.inc ${WRKSRC}
.for F in libpd packetdrill checksum_test packet_parser_test packet_to_string_test
	${MKDIR} ${WRKSRC}/${F}
	${INSTALL_DATA} ${FILESDIR}/Makefile.${F} ${WRKSRC}/${F}/Makefile
.endfor

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${INSTALL_DATA} ${PORTEXAMPLES} ${EXAMPLESDIR}
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
