# Created by: Antony Mawer <ports@mawer.org>
# $FreeBSD$

PORTNAME=	cntlm
PORTVERSION=	0.92.3
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	NTLM / NTLM Session Response / NTLMv2 authenticating HTTP proxy

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_RC_SUBR=	cntlm
USES=		gmake
HAS_CONFIGURE=	yes
ALL_TARGET=	cntlm

post-patch:
	@${REINPLACE_CMD} -e \
		's|$$(DESTDIR)/etc|$$(PREFIX)/etc| ; \
		 s|^CC=|CC?=| ; \
		 s| -Wno-unused-but-set-variable | | ; \
		 s| -pedantic | | ; \
		 s| -O3 | | ; \
		 s|@$$(CC)|$$(CC)| ; \
		 s|@if|if| ; \
		 s|-lpthread|-pthread|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e \
		's|^CCS=|#CCS=| ; \
		 s|mv |: | ; \
		 s|ln |: |' ${WRKSRC}/configure

post-build:
	@${LN} -sf cntlm.conf ${WRKSRC}/doc/cntlm.conf.sample

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} cntlm \
		${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} cntlm.conf.sample \
		${STAGEDIR}${PREFIX}/etc)
	(cd ${WRKSRC}/doc && ${INSTALL_MAN} cntlm.1 \
		${STAGEDIR}${MANPREFIX}/man/man1)

.include <bsd.port.mk>
