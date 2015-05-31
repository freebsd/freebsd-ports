# Created by: Anton Lysenok <bart@tapolsky.net.ua>
# $FreeBSD$

PORTNAME=	smfsav
PORTVERSION=	1.4.0
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	SF/smfs
DISTNAME=	smf-sav-${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	sasaki@fcc.ad.jp
COMMENT=	Sendmail Sender Address Validator

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USERS=		smfs
GROUPS=		smfs

OPTIONS_DEFINE=	DOCS

USE_RC_SUBR=	smfsav

CPPFLAGS+=	-D_REENTRANT
LDFLAGS+=	-lmilter -lpthread

SMFSAV_RUN_DIR?=/var/run/smfsav
SUB_FILES+=	pkg-message

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/readme

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} ${CPPFLAGS} -o smf-sav smf-sav.c ${LDFLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/smf-sav ${STAGEDIR}${PREFIX}/sbin/smfsav
	${INSTALL_DATA} ${WRKSRC}/smf-sav.conf ${STAGEDIR}${PREFIX}/etc/smfsav.conf.sample
	@${MKDIR} ${STAGEDIR}${SMFSAV_RUN_DIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ChangeLog readme ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
