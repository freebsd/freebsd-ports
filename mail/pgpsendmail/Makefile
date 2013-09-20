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

BUILD_DEPENDS=	pgp:${PORTSDIR}/security/pgp

WRKSRC=		${WRKDIR}/${PORTNAME}


MAN1=		pgppipe.1 sendpgppass.1
MAN8=		pgpsendmail.8 pgpdaemon.8
PLIST_FILES=	bin/pgpdaemon bin/pgppipe bin/sendpgppass libexec/pgpsendmail

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e \
		's|^CC =|CC ?=| ; \
		 s|^CFLAGS =|CFLAGS +=| ; \
		 /^all:/s|clean|| ; \
		 /install /s|^|#| ; \
		 s|-s -o|-o| ; \
		 /pgpsendmail.h/s|^|#|' ${WRKSRC}/Makefile

do-install:
.for i in pgpdaemon pgppipe sendpgppass
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} ${i} ${PREFIX}/bin)
.endfor
.for i in pgpsendmail
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} ${i} ${PREFIX}/libexec)
.endfor
.for i in ${MAN1}
	(cd ${WRKSRC}/doc && ${INSTALL_MAN} ${i} ${MAN1PREFIX}/man/man1)
.endfor
.for i in ${MAN8}
	(cd ${WRKSRC}/doc && ${INSTALL_MAN} ${i} ${MAN8PREFIX}/man/man8)
.endfor

.include <bsd.port.mk>
