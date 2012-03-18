# New ports collection makefile for:	ch
# Date created:				2 August 2006
# Whom:					conrads@cox.net
#
# $FreeBSD$
#

PORTNAME=	ch
PORTVERSION=	7.0.0
CATEGORIES=	shells
MASTER_SITES=	http://www.softintegration.com/download/software/release/FreeBSD/
DISTNAME=	chstandard-${PORTVERSION}.freebsd5.1

MAINTAINER=	5u623l20@gmail.com
COMMENT=	An embeddable C/C++ interpreter/shell

IA32_BINARY_PORT=	yes
NO_BUILD=	yes

DATADIR=	${PREFIX}/${PORTNAME}

SUB_FILES=	${PORTNAME}

MAN1=		installpkg.1 strconcat.1 strjoin.1. strputc.1 pkginstall.1 strgetc.1 gnuplot.1 str2mat.1 createpkg.1 str2ascii.1 strrep.1 splint.1 ch.1 foreach.1 stradd.1
MAN1PREFIX=	${PREFIX}/${PORTNAME}/docs
MANCOMPRESSED=	no

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64
LIB32_DEPENDS+=	c.4:${PORTSDIR}/misc/compat4x
.else
LIB_DEPENDS+=	c.4:${PORTSDIR}/misc/compat4x
.endif

do-install:
	${MKDIR} ${DATADIR}
	${TAR} zxf ${WRKSRC}/ch.bin -C ${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin
	${CHOWN} -R -h ${BINOWN}:${BINGRP} ${DATADIR}

post-install:
	@if ${GREP} -q '${PREFIX}/bin/ch' /etc/shells; then ${TRUE}; else \
		${ECHO_CMD} '${PREFIX}/bin/ch' >> /etc/shells; fi

.include <bsd.port.post.mk>
