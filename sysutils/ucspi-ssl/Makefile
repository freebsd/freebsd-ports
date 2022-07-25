PORTNAME=	ucspi-ssl
PORTVERSION=	0.99b
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.fehcom.de/ipnet/ucspi-ssl/

MAINTAINER=	freebsd@charles.lecklider.org
COMMENT=	UCSPI tools for building SSL client-server applications

RUN_DEPENDS=	tcpserver:sysutils/ucspi-tcp \
		${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

USES=		perl5 ssl tar:tgz
CFLAGS+=	-I${OPENSSLINC} -fcommon

WRKSRC=		${WRKDIR}/host/superscript.com/net/${DISTNAME}

PORTDOCS=	CERTS CHAIN-SSL CHANGES TODO UCSPI-SSL

SCRIPTS_TO_INSTALL=	https@ sslcat sslconnect

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

post-patch:
.for x in ${SCRIPTS_TO_INSTALL}
	@${REINPLACE_CMD} -i ''	-e 's|HOME/command/|${PREFIX}/bin/|' \
		${WRKSRC}/src/${x}.sh
.endfor

do-configure:
	${ECHO_CMD} "${CC} ${CFLAGS}" > ${WRKSRC}/conf-cc
	${ECHO_CMD} "${CC} ${CFLAGS}" > ${WRKSRC}/conf-ld
	${ECHO_CMD} "${PREFIX}" > ${WRKSRC}/conf-home
	${ECHO_CMD} "${PREFIX}/bin" > ${WRKSRC}/conf-tcpbin
	${ECHO_CMD} "/etc/ssl" > ${WRKSRC}/conf-cadir
	${ECHO_CMD} "/etc/ssl/cert.pem" > ${WRKSRC}/conf-cafile
	${ECHO_CMD} "/etc/ssl/dh1024.pem" > ${WRKSRC}/conf-dhfile
.if ${SSL_DEFAULT} != base
	${ECHO_CMD} "-lssl -lcrypto -L${LOCALBASE}/lib" > ${WRKSRC}/conf-ssllib
.endif

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} package/compile

do-install:
.for x in ${SCRIPTS_TO_INSTALL}
	${INSTALL_SCRIPT} ${WRKSRC}/command/${x} ${STAGEDIR}${PREFIX}/bin
.endfor
.for x in sslclient sslserver sslperl
	${INSTALL_PROGRAM} ${WRKSRC}/command/${x} ${STAGEDIR}${PREFIX}/bin
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
