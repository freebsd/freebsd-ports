# Created by: conrads@cox.net
# $FreeBSD$

PORTNAME=	ch
PORTVERSION=	7.0.0
PORTREVISION=	1
CATEGORIES=	shells
MASTER_SITES=	http://www.softintegration.com/download/software/release/FreeBSD/
DISTNAME=	chstandard-${PORTVERSION}.freebsd9.0

MAINTAINER=	conrads@cox.net
COMMENT=	An embeddable C/C++ interpreter/shell

IA32_BINARY_PORT=	yes
NO_BUILD=	yes

DATADIR=	${PREFIX}/${PORTNAME}

SUB_FILES=	${PORTNAME}
PORTDATA= README  bin config demos dl extern include lib license package sbin toolkit

MAN1=		installpkg.1 strconcat.1 strjoin.1. strputc.1 pkginstall.1 strgetc.1 gnuplot.1 str2mat.1 createpkg.1 str2ascii.1 strrep.1 splint.1 ch.1 foreach.1 stradd.1
MAN1PREFIX=	${PREFIX}/${PORTNAME}/docs
MANCOMPRESSED=	no

NO_STAGE=	yes
.include <bsd.port.pre.mk>

post-extract:
	@${MKDIR} ${WRKSRC}/ch
	@${TAR} zxf ${WRKSRC}/ch.bin -C ${WRKSRC}/ch

do-install:
	${MKDIR} ${DATADIR}
	cd ${WRKSRC}/ch && ${COPYTREE_SHARE} \* ${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin
	${CHOWN} -R -h ${BINOWN}:${BINGRP} ${DATADIR}

post-install:
	@if ${GREP} -q '${PREFIX}/bin/ch' /etc/shells; then ${TRUE}; else \
		${ECHO_CMD} '${PREFIX}/bin/ch' >> /etc/shells; fi

.include <bsd.port.post.mk>
