# New ports collection makefile for:	ucspi-ssl
# Date created:		2003-07-09
# Whom:			David Thiel <lx@redundancy.redundancy.org>
#
# $FreeBSD$
#

PORTNAME=	ucspi-ssl
PORTVERSION=	0.68
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.superscript.com/ucspi-ssl/

MAINTAINER=	lx@redundancy.redundancy.org
COMMENT=	UCSPI tools for building SSL client-server applications

RUN_DEPENDS=	tcpserver:${PORTSDIR}/sysutils/ucspi-tcp

USE_PERL5=	yes

NO_PACKAGE=	Non-explicit licensing terms

DOCS=		CHANGES TODO UCSPI-SSL

WRKSRC=		${WRKDIR}/host/superscript.com/net/${DISTNAME}

SCRIPTS_TO_INSTALL=	https@ sslcat sslconnect

post-patch:
.for x in ${SCRIPTS_TO_INSTALL}
	@${PERL} -pi.orig \
		-e 's|HOME/command/|${PREFIX}/bin/|' \
		${WRKSRC}/src/${x}.sh
.endfor

do-configure:
	${ECHO_CMD} "${CC} ${CFLAGS}" > ${WRKSRC}/src/conf-cc
	${ECHO_CMD} "${PREFIX}" > ${WRKSRC}/src/conf-home
	${ECHO_CMD} "${PREFIX}/bin" > ${WRKSRC}/src/conf-tcpbin
	${ECHO_CMD} "${PREFIX}/ssl/certs" > ${WRKSRC}/src/conf-cadir

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		"requires Perl 5.6.0 or greater. Please install lang/perl5 and retry"
.endif

do-build:
	cd ${WRKSRC} && package/compile

do-install:
.for x in ${SCRIPTS_TO_INSTALL}
	${INSTALL_SCRIPT} ${WRKSRC}/command/${x} ${PREFIX}/bin
.endfor
.for x in sslclient sslserver sslperl
	${INSTALL_PROGRAM} ${WRKSRC}/command/${x} ${PREFIX}/bin
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/src && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
