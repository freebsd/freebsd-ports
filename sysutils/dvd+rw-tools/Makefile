# New ports collection makefile for: dvd+rw-tools
# Date created:        2003-6-15
# Whom:                chuck@pkix.net
#
# $FreeBSD$

PORTNAME=	dvd+rw-tools
PORTVERSION=	7.1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.pkix.net/mirror/fy.chalmers.se/ \
		http://fy.chalmers.se/~appro/linux/DVD+RW/tools/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DVD burning software

USE_CDRTOOLS=	yes

MAN1=		growisofs.1
BIN_FILES=	growisofs dvd+rw-format dvd+rw-booktype dvd+rw-mediainfo dvd-ram-control
PLIST_FILES=	${BIN_FILES:S|^|bin/|}
PORTDOCS=	index.html

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's/-D_THREAS_SAFE/-D_THREAD_SAFE/' \
		-e 's/-D_THREAD_SAFE/-D_THREAD_SAFE ${PTHREAD_CFLAGS}/' \
		-e 's/-pthread/${PTHREAD_LIBS}/' \
		-e 's/-O2//' \
		${WRKSRC}/Makefile.m4

do-install:
.for i in ${BIN_FILES}
	${INSTALL_PROGRAM} ${WRKSRC}/${i} ${PREFIX}/bin
.endfor
	${INSTALL_MAN} ${WRKSRC}/growisofs.1 ${MANPREFIX}/man/man1/

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/index.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
