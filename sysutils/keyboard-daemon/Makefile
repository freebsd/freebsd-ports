# $FreeBSD$

PORTNAME=	keyboard-daemon
PORTVERSION=	0.7
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.bayofrum.net/dist/${PORTNAME}/

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Listens on a keyboard device and executes commands on keypresses

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libcfu.so:devel/libcfu

USES=		tar:bzip2

USE_RC_SUBR=	${PORTNAME:S/-/_/}
PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz
PORTEXAMPLES=	*

OPTIONS_DEFINE=	EXAMPLES

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1.gz ${STAGEDIR}${MAN1PREFIX}/man/man1/
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	for f in ${WRKSRC}/examples/*; do	\
	    ${INSTALL_DATA} $$f ${STAGEDIR}${EXAMPLESDIR};	\
	done
.endif

.include <bsd.port.mk>
