# $FreeBSD$

PORTNAME=	packetdrill
PORTVERSION=	0.0.20130820
CATEGORIES=	net ipv6
MASTER_SITES=	LOCAL/hrs
DISTNAME=	${PORTNAME}-ea8f2fec724d

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Network stack testing tool

LICENSE=	GPLv2

USES=		bison uidfix
MAKE_ENV+=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"
PORTDATA=	packetdrill.el packetdrill.vim
PORTDOCS=	README
PORTEXAMPLES=	tests

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
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/contrib && ${INSTALL_DATA} ${PORTDATA} \
	    ${STAGEDIR}${DATADIR}
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} ${PORTEXAMPLES} \
	    ${STAGEDIR}${EXAMPLESDIR}
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
