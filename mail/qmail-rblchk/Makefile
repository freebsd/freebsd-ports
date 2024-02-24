PORTNAME=	qmail-rblchk
PORTVERSION=	2.4.1
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	http://www.morettoni.net/qmail/ \
		LOCAL/ehaupt

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Qmail RBL filter
WWW=		http://www.morettoni.net/qmail-rblchk.en.html

USES=		groff qmail:run

ALL_TARGET=	default
INSTALL_TARGET=	setup

CFLAGS?=	-O2 -Wimplicit -Wunused -Wcomment -Wchar-subscripts -Wuninitialized \
		-Wshadow -Wcast-qual -Wcast-align -Wwrite-strings
LDFLAGS?=	-s

WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS_DEFINE=	EXAMPLES

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

post-patch:
	@${REINPLACE_CMD} -e '/"cat/d; s|,02755|,0755|' \
		-e 's|\"man|\"share/man|g' \
		${WRKSRC}/hier.c

do-configure:
	${PRINTF}   "${STAGEDIR}${PREFIX}\n\n.../bin.\n"	> ${WRKSRC}/conf-home
	${ECHO_CMD} "${CC} ${CFLAGS}"		> ${WRKSRC}/conf-cc
	${ECHO_CMD} "${CC} ${LDFLAGS}"		> ${WRKSRC}/conf-ld

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for f in rbllist.sh spam-report.sh dot-qmail-storeip
	${INSTALL_DATA} ${WRKSRC}/contrib/${f} ${STAGEDIR}${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>
