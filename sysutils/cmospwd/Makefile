# New ports collection makefile for:	cmospwd
# Date created:				28 Jul 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	cmospwd
PORTVERSION=	4.6
CATEGORIES=	sysutils
MASTER_SITES=	http://www.cgsecurity.org/

MAINTAINER=	ehaupt@critical.ch
COMMENT=	A BIOS password recovery tool

USE_REINPLACE=	yes

PLIST_FILES=	bin/cmospwd
PORTDOCS=	cmospwd.txt

ONLY_FOR_ARCHS=	i386 amd64

.include <bsd.port.pre.mk>

post-patch:
.if ${OSVERSION} < 500000
	@${REINPLACE_CMD} -e 's|<stdint\.h>|<unistd.h>|' \
		${WRKSRC}/src/cmospwd.c
.endif
.if !defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e "s/`${ECHO_CMD} -e '\r'`*$$//" \
		${WRKSRC}/cmospwd.txt
.endif

do-build:
	${CC} ${CFLAGS} ${WRKSRC}/src/${PORTNAME}.c -o ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
