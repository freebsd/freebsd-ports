# New ports collection makefile for: checkpassword
# Date created:		05 August 1998
# Whom:			sada@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	checkpassword
PORTVERSION=	0.90
CATEGORIES=	security
MASTER_SITES=	http://cr.yp.to/checkpwd/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple password-checking interface

ALL_TARGET=	it
INSTALL_TARGET=	setup
#MAN8=		checkpassword.8
RESTRICTED=	"Unsure of djb's license"

DOCDIR=		${PREFIX}/share/doc/checkpassword

.SILENT:

do-configure:
	${ECHO_CMD} 'cc -s -lcrypt' > ${WRKSRC}/conf-ld
	${ECHO_CMD} ${PREFIX} >${WRKSRC}/conf-home

post-install:
#	${INSTALL_MAN} ${WRKSRC}/${MAN8} ${PREFIX}/man/man8
	${MKDIR} ${DOCDIR}
.for f in CHANGES FILES README SYSDEPS TARGETS TODO VERSION
	${INSTALL_DATA} ${WRKSRC}/$f ${DOCDIR}
.endfor

.include <bsd.port.mk>
