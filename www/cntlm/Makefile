# Created by: Antony Mawer <ports@mawer.org>
# $FreeBSD$

PORTNAME=	cntlm
PORTVERSION=	0.92.3
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20${PORTVERSION}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	NTLM / NTLM Session Response / NTLMv2 authenticating HTTP proxy

LICENSE=	GPLv2

USE_RC_SUBR=	cntlm
HAS_CONFIGURE=	yes
USE_GMAKE=	yes
ALL_TARGET=	cntlm

MAN1=		cntlm.1

post-patch:
	@${REINPLACE_CMD} -e 's|DESTDIR=|DESTDIR=${PREFIX}|' \
		-e 's|-Wno-unused-but-set-variable -pedantic -O3||' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cntlm ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/doc/cntlm.conf ${PREFIX}/etc/cntlm.conf.sample
	${INSTALL_MAN} ${WRKSRC}/doc/cntlm.1 ${MAN1PREFIX}/man/man1

post-install:
	@if [ ! -f ${PREFIX}/etc/cntlm.conf ]; then \
		${CP} -p ${PREFIX}/etc/cntlm.conf.sample ${PREFIX}/etc/cntlm.conf; \
	fi

.include <bsd.port.mk>
