# New ports collection makefile for: checkpassword
# Date created:		05 August 1998
# Whom:			sada@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	checkpassword
PORTVERSION=	0.81
CATEGORIES=	security
MASTER_SITES=	http://cr.yp.to/software/ \
		${MASTER_SITE_LOCAL} \
		${MASTER_SITE_PORTS_JP}
MASTER_SITE_SUBDIR=	sada

MAINTAINER=	sada@FreeBSD.org

ALL_TARGET=	it
INSTALL_TARGET=	setup
MAN8=		checkpassword.8
RESTRICTED=	"Unsure of djb's license"

DOCDIR=		${PREFIX}/share/doc/checkpassword

.SILENT:

do-configure:
	${ECHO} 'cc -s -lcrypt' > ${WRKSRC}/conf-ld
	${ECHO} ${PREFIX} >${WRKSRC}/conf-home

post-install:
	${INSTALL_MAN} ${WRKSRC}/${MAN8} ${PREFIX}/man/man8
	${MKDIR} ${DOCDIR}
.for f in BLURB CHANGES FILES INSTALL README SYSDEPS TARGETS THANKS TODO
	${INSTALL_DATA} ${WRKSRC}/$f ${DOCDIR}
.endfor

.include <bsd.port.mk>
