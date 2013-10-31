# Created by: sada@FreeBSD.org
# $FreeBSD$

PORTNAME=	checkpassword
PORTVERSION=	0.90
CATEGORIES=	security
MASTER_SITES=	http://cr.yp.to/checkpwd/ \
		${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=	distfiles

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Simple password-checking interface

OPTIONS_DEFINE=	DOCS

ALL_TARGET=	it
INSTALL_TARGET=	setup

PLIST_FILES=	bin/checkpassword
PORTDOCS=	CHANGES FILES README SYSDEPS TARGETS TODO VERSION

post-patch:
	@${REINPLACE_CMD} -e "s,gcc,${CC},g" ${WRKSRC}/find-systype.sh

do-configure:
	@${ECHO_CMD} '${CC} ${CFLAGS} -s -lcrypt' > ${WRKSRC}/conf-cc
	@${ECHO_CMD} '${CC} ${CFLAGS} -s -lcrypt' > ${WRKSRC}/conf-ld
	@${ECHO_CMD} ${STAGEDIR}${PREFIX} >${WRKSRC}/conf-home

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
