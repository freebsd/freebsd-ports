# New ports collection makefile for: dvd+rw-tools
# Date created:        2003-6-15
# Whom:                chuck@pkix.net
#
# $FreeBSD$

PORTNAME=	dvd+rw-tools
PORTVERSION=	5.20.4.10.8
CATEGORIES=	sysutils
MASTER_SITES=	http://www.pkix.net/mirror/fy.chalmers.se/ \
		http://fy.chalmers.se/~appro/linux/DVD+RW/tools/

MAINTAINER=	chuck@pkix.net
COMMENT=	DVD burning software

RUN_DEPENDS=	${LOCALBASE}/bin/mkisofs:${PORTSDIR}/sysutils/cdrtools

USE_REINPLACE=	yes

MAN1=		growisofs.1
BIN_FILES=	growisofs dvd+rw-format dvd+rw-booktype dvd+rw-mediainfo dvd-ram-control
PLIST_FILES=	${BIN_FILES:S|^|bin/|}
PORTDOCS=	index.html

post-patch:
	${REINPLACE_CMD} -e 's/-O2//' ${WRKSRC}/Makefile.m4

do-install:
.for i in ${BIN_FILES}
	${INSTALL_PROGRAM} ${WRKSRC}/${i} ${PREFIX}/bin
.endfor
	${INSTALL_MAN} ${WRKSRC}/growisofs.1 ${MANPREFIX}/man/man1/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/index.html ${DOCSDIR}/
.endif

.include <bsd.port.mk>
