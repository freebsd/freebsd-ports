# Created by: Antony Mawer <ports@mawer.org>
# $FreeBSD$

PORTNAME=	cntlm
PORTVERSION=	0.92.3
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	NTLM / NTLM Session Response / NTLMv2 authenticating HTTP proxy

LICENSE=	GPLv2

USE_RC_SUBR=	cntlm
USES=		gmake
HAS_CONFIGURE=	yes
ALL_TARGET=	cntlm

post-patch:
	@${REINPLACE_CMD} -e 's|DESTDIR=|DESTDIR=${PREFIX}|' \
		-e 's|CC=|CC?=|' \
		-e 's|-Wno-unused-but-set-variable -pedantic -O3||' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cntlm ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/doc/cntlm.conf ${STAGEDIR}${PREFIX}/etc/cntlm.conf.sample
	${INSTALL_MAN} ${WRKSRC}/doc/cntlm.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
