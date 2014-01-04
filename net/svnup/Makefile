# $FreeBSD$

PORTNAME=	svnup
PORTVERSION=	1.02
CATEGORIES=	net
MASTER_SITES=	http://jcm.dsl.visi.com/freebsd/svnup/ \
		LOCAL/jgh/net/${PORTNAME}/

MAINTAINER=	jcm@visi.com
COMMENT=	Lightweight program to pull source from an Apache Subversion server

LICENSE=	BSD

LDFLAGS+=	-lmd -lssl
USE_XZ=	yes

post-patch-script:
	@${REINPLACE_CMD} -e 's|\/stable\/8|\/stable\/${OSREL:R}|' ${WRKSRC}/svnup.conf
	@${REINPLACE_CMD} -e 's|\/releng\/8.3|\/releng\/${OSREL}|' ${WRKSRC}/svnup.conf

do-build:
	cd ${WRKSRC} && \
		${CC} -o ${PORTNAME} ${CFLAGS} ${PORTNAME}.c ${LDFLAGS}

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.conf.5 ${STAGEDIR}${MAN5PREFIX}/man/man5

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample
	@if [ ! -e "${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf" ]; then \
		${ECHO_MSG} "   Installing local configuration file: ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf"; \
		${CP} ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf; \
	else \
		${ECHO_MSG} "   Preserving local configuration file: ${STAGEDIR}${ETCDIR}/${PORTNAME}.conf"; \
	fi

.include <bsd.port.mk>
