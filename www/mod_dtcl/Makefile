# New ports collection makefile for:	mod_dtcl
# Date created:				January 9, 1999
# Whom:					Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	mod_dtcl
PORTVERSION=	0.12.0
CATEGORIES=	www tcl83
MASTER_SITES=	http://tcl.apache.org/mod_dtcl/download/

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Embeds a TCL8 interpreter in the Apache server

BUILD_DEPENDS=	${APXS}:${PORTSDIR}/${APACHE_PORT}
LIB_DEPENDS=	tcl83:${PORTSDIR}/lang/tcl83

WRKSRC=		${WRKDIR}/mod_dtcl
MAKEFILE=	${FILESDIR}/Makefile.bsd

do-install:
	${INSTALL_DATA} ${WRKSRC}/libmod_dtcl.so.1* \
		${PREFIX}/libexec/apache/mod_dtcl.so
	${PREFIX}/sbin/apxs -e -A -n dtcl ${PREFIX}/libexec/apache/mod_dtcl.so
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/mod_dtcl
	${INSTALL_DATA} ${WRKSRC}/docs/*.?tml ${WRKSRC}/docs/*.gif \
		${PREFIX}/share/doc/mod_dtcl
	${SED} 's,/usr/local,${LOCALBASE},g' ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
