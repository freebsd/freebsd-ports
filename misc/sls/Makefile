PORTNAME=	sls
PORTVERSION=	1.00
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	LOCAL/dannyboy
DISTNAME=	${PORTNAME}

MAINTAINER=	sec@42.org
COMMENT=	List information about file(s) and directories

WRKSRC=		${WRKDIR}/sls

PLIST_FILES=	bin/sls \
		share/man/man1/sls.1.gz

ALL_TARGET=	sls

post-patch:
	@${REINPLACE_CMD} -e 's|CFLAGS|#&|' ${WRKSRC}/Makefile

do-install:
	${CP} ${WRKSRC}/sls ${STAGEDIR}${PREFIX}/bin
	${CP} ${WRKSRC}/sls.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
