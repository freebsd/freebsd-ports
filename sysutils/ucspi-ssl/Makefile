# New ports collection makefile for:	ucspi-ssl
# Date created:		2003-07-09
# Whom:			David Thiel <lx@redundancy.redundancy.org>
#
# $FreeBSD$
#

PORTNAME=	ucspi-ssl
PORTVERSION=	0.67
CATEGORIES=	sysutils
MASTER_SITES=	http://www.superscript.com/ucspi-ssl/

MAINTAINER=	lx@redundancy.redundancy.org
COMMENT=	UCSPI tools for building SSL client-server applications

RUN_DEPENDS=	tcpserver:${PORTSDIR}/sysutils/ucspi-tcp

NO_PACKAGE=	Non-explicit licensing terms

DOCS=		CHANGES TODO UCSPI-SSL

WRKSRC=		${WRKDIR}/host/superscript.com/net/${DISTNAME}

do-configure:
	${ECHO_CMD} "${CC} ${CFLAGS}" > ${WRKSRC}/src/conf-cc
	${ECHO_CMD} "${PREFIX}" > ${WRKSRC}/src/conf-home
	${ECHO_CMD} "${PREFIX}/bin" > ${WRKSRC}/src/conf-tcpbin
	${ECHO_CMD} "${PREFIX}/ssl/certs" > ${WRKSRC}/src/conf-cadir

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_SSLPERL)
.if ${PERL_LEVEL} < 500600
IGNORE=		"requires Perl 5.6.0 or greater. Please install lang/perl5 and retry, or define WITHOUT_SSLPERL"
.endif
.else
PLIST_SUB+=	SSLPERL="@comment "
.endif

do-build:
.if defined(WITHOUT_SSLPERL)
	cd ${WRKSRC} && package/compile https@ sslcat sslconnect sslclient sslserver
.else
	cd ${WRKSRC} && package/compile
.endif

do-install:
.for x in https@ sslcat sslconnect
	${INSTALL_SCRIPT} ${WRKSRC}/command/${x} ${PREFIX}/bin
.endfor
.for x in sslclient sslserver
	${INSTALL_PROGRAM} ${WRKSRC}/command/${x} ${PREFIX}/bin
.endfor
.if !defined(WITHOUT_SSLPERL)
	${INSTALL_PROGRAM} ${WRKSRC}/command/sslperl ${PREFIX}/bin
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/src && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
