PORTNAME=	qmail-rblchk
PORTVERSION=	2.4.1
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.morettoni.net/qmail/ \
		LOCAL/ehaupt

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Qmail RBL filter

USES=		groff qmail:run

LDFLAGS?=	-s
CFLAGS?=	-O2 -Wimplicit -Wunused -Wcomment -Wchar-subscripts -Wuninitialized \
		-Wshadow -Wcast-qual -Wcast-align -Wwrite-strings

WRKSRC=		${WRKDIR}/${PORTNAME}

ALL_TARGET=	default
INSTALL_TARGET=	setup

OPTIONS_DEFINE=	EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e '/"cat/d; s|,02755|,0755|' ${WRKSRC}/hier.c

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
