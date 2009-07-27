# New ports collection makefile for:   cntlm
# Date created:        23 July 2009
# Whom:                Antony Mawer <ports@mawer.org>
#
# $FreeBSD$
#

PORTNAME=	cntlm
PORTVERSION=	0.35.1
CATEGORIES=	www
MASTER_SITES=	SF

MAINTAINER=	ports@mawer.org
COMMENT=	An NTLM / NTLM Session Response / NTLMv2 authenticating HTTP proxy

USE_RC_SUBR=	cntlm
HAS_CONFIGURE=	yes
ALL_TARGET=	cntlm
MAN1=		cntlm.1

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' \
	    ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cntlm ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/doc/cntlm.conf ${PREFIX}/etc/cntlm.conf.sample
	${INSTALL_MAN} ${WRKSRC}/doc/cntlm.1 ${PREFIX}/man/man1

post-install:
	@if [ ! -f ${PREFIX}/etc/cntlm.conf ]; then \
	    ${CP} -p ${PREFIX}/etc/cntlm.conf.sample ${PREFIX}/etc/cntlm.conf; \
	fi

.include <bsd.port.post.mk>
