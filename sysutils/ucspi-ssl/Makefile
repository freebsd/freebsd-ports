# Created by: David Thiel <lx@redundancy.redundancy.org>
# $FreeBSD$

PORTNAME=	ucspi-ssl
PORTVERSION?=	0.70
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	LOCAL/garga/ucspi-ssl \
		http://www.superscript.com/ucspi-ssl/ \
		http://dev.qmailrocks.org/downloads/qmailrocks_3.0-beta/ \
		GENTOO

MAINTAINER?=	lx@FreeBSD.org
COMMENT?=	UCSPI tools for building SSL client-server applications

RUN_DEPENDS=	tcpserver:sysutils/ucspi-tcp \
		${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

CONFLICTS?=	ucspi-ssl-tls-[0-9]*

USES=		perl5

PORTDOCS=	CHANGES TODO UCSPI-SSL

WRKSRC=		${WRKDIR}/host/superscript.com/net/${DISTNAME}

SCRIPTS_TO_INSTALL=	https@ sslcat sslconnect

post-patch:
.for x in ${SCRIPTS_TO_INSTALL}
	@${REINPLACE_CMD} -i ''	-e 's|HOME/command/|${PREFIX}/bin/|' \
		${WRKSRC}/src/${x}.sh
.endfor

do-configure:
	${ECHO_CMD} "${CC} ${CFLAGS}" > ${WRKSRC}/src/conf-cc
	${ECHO_CMD} "${CC} ${CFLAGS}" > ${WRKSRC}/src/conf-ld
	${ECHO_CMD} "${PREFIX}" > ${WRKSRC}/src/conf-home
	${ECHO_CMD} "${PREFIX}/bin" > ${WRKSRC}/src/conf-tcpbin
	${ECHO_CMD} "/etc/ssl" > ${WRKSRC}/src/conf-cadir
	${ECHO_CMD} "/etc/ssl/cert.pem" > ${WRKSRC}/src/conf-cafile
	${ECHO_CMD} "/etc/ssl/dh1024.pem" > ${WRKSRC}/src/conf-dhfile

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
	cd ${WRKSRC}/src && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
