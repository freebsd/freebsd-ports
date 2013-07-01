# $FreeBSD$

PORTNAME=	svnup
PORTVERSION=	0.97
CATEGORIES=	net
MASTER_SITES=	http://jcm.dsl.visi.com/freebsd/svnup/ \
		LOCAL/jgh/net/${PORTNAME}/

MAINTAINER=	jcm@visi.com
COMMENT=	Lightweight program to pull source from an Apache Subversion server

LICENSE=	BSD

LDFLAGS+=	-lmd -lssl
USE_XZ=	yes

MAN1=	${PORTNAME}.1
MAN5=	${PORTNAME}.conf.5
PORTDOCS=	ChangeLog

post-patch-script:
	@${REINPLACE_CMD} -e 's|8.3|${OSREL}|' ${WRKSRC}/svnup.conf

do-build:
	cd ${WRKSRC} && \
		${CC} -o ${PORTNAME} ${CFLAGS} ${PORTNAME}.c ${LDFLAGS}

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/${MAN5} ${MAN5PREFIX}/man/man5

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${DOCSDIR}
.endif
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf ${PREFIX}/etc/${PORTNAME}.conf.sample
	@if [ ! -e "${PREFIX}/etc/${PORTNAME}.conf" ]; then \
		${ECHO_MSG} "   Installing local configuration file: ${PREFIX}/etc/${PORTNAME}.conf"; \
		${CP} ${PREFIX}/etc/${PORTNAME}.conf.sample ${PREFIX}/etc/${PORTNAME}.conf; \
	else \
		${ECHO_MSG} "   Preserving local configuration file: ${ETCDIR}/${PORTNAME}.conf"; \
	fi

.include <bsd.port.mk>
