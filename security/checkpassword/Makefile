# New ports collection makefile for: checkpassword
# Date created:		05 August 1998
# Whom:			sada@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	checkpassword
PORTVERSION=	0.90
CATEGORIES=	security
MASTER_SITES=	http://cr.yp.to/checkpwd/ \
		${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=	distfiles

MAINTAINER=	garga@FreeBSD.org
COMMENT=	A simple password-checking interface

ALL_TARGET=	it
INSTALL_TARGET=	setup

PLIST_FILES=	bin/checkpassword
PORTDOCS=	CHANGES FILES README SYSDEPS TARGETS TODO VERSION

do-configure:
	@${ECHO_CMD} '${CC} ${CFLAGS} -s -lcrypt' > ${WRKSRC}/conf-ld
	@${ECHO_CMD} ${PREFIX} >${WRKSRC}/conf-home

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
