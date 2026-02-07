PORTNAME=	keyboard-daemon
PORTVERSION=	0.7
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.bayofrum.net/dist/${PORTNAME}/

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Listens on a keyboard device and executes commands on keypresses
WWW=		https://www.bayofrum.net/cgi-bin/fossil/keyboard-daemon/

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libcfu.so:devel/libcfu

USES=		tar:bzip2

USE_RC_SUBR=	${PORTNAME:S/-/_/}
PLIST_FILES=	bin/${PORTNAME} share/man/man1/${PORTNAME}.1.gz
PORTEXAMPLES=	*

OPTIONS_DEFINE=	EXAMPLES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1.gz ${STAGEDIR}${PREFIX}/share/man/man1/

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	for f in ${WRKSRC}/examples/*; do	\
	    ${INSTALL_DATA} $$f ${STAGEDIR}${EXAMPLESDIR};	\
	done

.include <bsd.port.mk>
