# $FreeBSD$

PORTNAME=	svnup
PORTVERSION=	1.03
CATEGORIES=	net
MASTER_SITES=	http://jcm.dsl.visi.com/freebsd/svnup/ \
		LOCAL/jgh/net/${PORTNAME}/

MAINTAINER=	jcm@visi.com
COMMENT=	Lightweight program to pull source from an Apache Subversion server

OPTIONS_DEFINE=	DOCS

LICENSE=	BSD2CLAUSE

LDFLAGS+=	-lmd -lssl
USES=		tar:xz
PORTDOCS=	ChangeLog

post-patch:
	@${REINPLACE_CMD} -e 's|\/stable\/8|\/stable\/${OSREL:R}| ; \
		s|\/releng\/8.3|\/releng\/${OSREL}|' \
		${WRKSRC}/svnup.conf

do-build:
	cd ${WRKSRC} && \
		${CC} -o ${PORTNAME} ${CFLAGS} ${PORTNAME}.c ${LDFLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.conf.5 ${STAGEDIR}${MAN5PREFIX}/man/man5
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample

.include <bsd.port.mk>
