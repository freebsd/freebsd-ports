# New ports collection makefile for:	ucspi-ssl
# Date created:		2003-07-09
# Whom:			David Thiel <lx@redundancy.redundancy.org>
#
# $FreeBSD$
#

PORTNAME=	ucspi-ssl
PORTVERSION=	0.50
CATEGORIES=	sysutils
MASTER_SITES=	http://www.superscript.com/ucspi-ssl/

MAINTAINER=	lx@redundancy.redundancy.org
COMMENT=	"UCSPI tools for building SSL client-server applications"

RUN_DEPENDS=	tcpserver:${PORTSDIR}/sysutils/ucspi-tcp

NO_PACKAGE=     "Non-explicit licensing terms"

ALL_TARGET=	it
INSTALL_TARGET=	setup check

DOCS=		CHANGES README TODO UCSPI-SSL

do-configure:
	${ECHO_CMD} "${CC} ${CFLAGS}" > ${WRKSRC}/conf-cc
	${ECHO_CMD} "${PREFIX}" > ${WRKSRC}/conf-home
	${ECHO_CMD} "${PREFIX}/bin" > ${WRKSRC}/conf-tcpbin
	${ECHO_CMD} "${PREFIX}/ssl/certs" > ${WRKSRC}/conf-cadir

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
