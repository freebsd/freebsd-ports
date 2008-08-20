# New ports collection makefile for:	ch
# Date created:				2 August 2006
# Whom:					conrads@cox.net
#
# $FreeBSD$
#

PORTNAME=	ch
PORTVERSION=	5.1.0
PORTREVISION=	2
CATEGORIES=	shells
MASTER_SITES=	http://www.softintegration.com/download/software/release/FreeBSD/
DISTNAME=	chstandard-${PORTVERSION}.freebsd5.1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An embeddable C/C++ interpreter/shell

IA32_BINARY_PORT=	yes
NO_BUILD=	yes

DATADIR=	${PREFIX}/${PORTNAME}

SUB_FILES=	${PORTNAME}

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
