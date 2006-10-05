# New ports collection makefile for:	ch
# Date created:				2 August 2006
# Whom:					conrads@cox.net
#
# $FreeBSD$
#

PORTNAME=	ch
PORTVERSION=	5.1.0
CATEGORIES=	shells
MASTER_SITES=	http://www.softintegration.com/download/software/release/FreeBSD/
DISTNAME=	chstandard-${PORTVERSION}.freebsd5.1

MAINTAINER=	conrads@cox.net
COMMENT=	An embeddable C/C++ interpreter/shell

# possibly ia64?
ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	is an i386 binary
NO_BUILD=	yes

DATADIR=	${PREFIX}/${PORTNAME}

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000
.if ${ARCH} == amd64
LIB32_DEPENDS+=	c.4:${PORTSDIR}/misc/compat4x
.else
LIB_DEPENDS+=	c.4:${PORTSDIR}/misc/compat4x
.endif
.endif

do-install:
	${MKDIR} ${DATADIR}
	${TAR} zxf ${WRKSRC}/ch.bin -C ${DATADIR}
	${LN} -s ${DATADIR}/bin/ch ${PREFIX}/bin

post-install:
	@if ${GREP} -q '${PREFIX}/bin/ch' /etc/shells; then ${TRUE}; else \
		${ECHO_CMD} '${PREFIX}/bin/ch' >> /etc/shells; fi

.include <bsd.port.post.mk>
