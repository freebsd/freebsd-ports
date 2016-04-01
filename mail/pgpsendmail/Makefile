# Created by: ache
# $FreeBSD$

PORTNAME=	pgpsendmail
PORTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.dhp.com/pub/crypto/pgp/PGPsendmail/
DISTNAME=	PGPsendmail-v${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PGP sign/encrypt/decrypt messages automatically

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

BUILD_DEPENDS=	pgp:security/pgp

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/pgpdaemon bin/pgppipe bin/sendpgppass libexec/pgpsendmail \
		man/man1/pgppipe.1.gz man/man1/sendpgppass.1.gz \
		man/man8/pgpsendmail.8.gz man/man8/pgpdaemon.8.gz

post-patch:
	@${REINPLACE_CMD} -e \
		's|^CC =|CC ?=| ; \
		 s|^CFLAGS =|CFLAGS +=| ; \
		 /^all:/s|clean|| ; \
		 /install /s|^|#| ; \
		 s|-s -o|-o| ; \
		 /pgpsendmail.h/s|^|#|' ${WRKSRC}/Makefile

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} pgpdaemon pgppipe sendpgppass \
		${STAGEDIR}${PREFIX}/bin)
	${INSTALL_PROGRAM} ${WRKSRC}/pgpsendmail ${STAGEDIR}${PREFIX}/libexec
	(cd ${WRKSRC}/doc && ${INSTALL_MAN} pgppipe.1 sendpgppass.1 \
		${STAGEDIR}${MAN1PREFIX}/man/man1)
	(cd ${WRKSRC}/doc && ${INSTALL_MAN} pgpsendmail.8  pgpdaemon.8 \
		${STAGEDIR}${MAN8PREFIX}/man/man8)

.include <bsd.port.mk>
