PORTNAME=	checkpassword
PORTVERSION=	0.90
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://cr.yp.to/checkpwd/

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Simple password-checking interface
WWW=		https://cr.yp.to/checkpwd.html

ALL_TARGET=	it
INSTALL_TARGET=	setup

PLIST_FILES=	bin/checkpassword
PORTDOCS=	CHANGES FILES README SYSDEPS TARGETS TODO VERSION

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e "s,gcc,${CC},g" ${WRKSRC}/find-systype.sh

do-configure:
	@${ECHO_CMD} '${CC} ${CFLAGS} -s -lcrypt' > ${WRKSRC}/conf-cc
	@${ECHO_CMD} '${CC} ${CFLAGS} -s -lcrypt' > ${WRKSRC}/conf-ld
	@${ECHO_CMD} ${STAGEDIR}${PREFIX} >${WRKSRC}/conf-home

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
