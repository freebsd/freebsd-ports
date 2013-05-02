# Created by: James Raftery <james@now.ie>
# $FreeBSD$

PORTNAME=	vodmr
PORTVERSION=	0.13
PORTREVISION=	1
CATEGORIES=	mail perl5
MASTER_SITES=	http://romana.now.ie/software/ \
		http://www.lecter.phlegethon.org/vodmr/

MAINTAINER=	james@now.ie
COMMENT=	ODMR/ATRN server for vpopmail+qmail

DEPRECATED=	depends on expired mail/p5-vpopmail
EXPIRATION_DATE=	2013-06-01

OPTIONS_DEFINE=	TCPSERVER
OPTIONS_DEFAULT=	TCPSERVER
TCPSERVER_DESC= Enable TCP server via sysutils/ucspi-tcp

.include <bsd.port.options.mk>

RUN_DEPENDS=	p5-CDB_File>=0:${PORTSDIR}/databases/p5-CDB_File \
		p5-vpopmail>=0:${PORTSDIR}/mail/p5-vpopmail \
		p5-Mail-Tools>=0:${PORTSDIR}/mail/p5-Mail-Tools \
		p5-Digest-HMAC>=0:${PORTSDIR}/security/p5-Digest-HMAC

.if ${PORT_OPTIONS:MTCPSERVER}
RUN_DEPENDS+=	tcpserver:${PORTSDIR}/sysutils/ucspi-tcp
.endif

NO_BUILD=	yes
USE_PERL5_RUN=	yes

SUB_FILES=	pkg-message
SUB_LIST=	SCRIPT="${PREFIX}/sbin/odmrd"

PORTDOCS=	FAQ README INSTALL INTERNALS TODO sample-odmrd.rules

do-configure:
	@${REINPLACE_CMD} -e 's|^\#!/usr/bin/perl|\#!${PERL}|' ${WRKSRC}/odmrd

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/odmrd ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${FILESDIR}/odmrd.sh-sample ${PREFIX}/etc/rc.d

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
