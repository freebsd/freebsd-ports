# Created by: Anton Lysenok <bart@tapolsky.net.ua>
# $FreeBSD$

PORTNAME=	smfsav
PORTVERSION=	2.1
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://smf-sav.anw.at/
PKGNAMESUFFIX=	-devel
DISTNAME=	smf-sav-reloaded-${PORTVERSION}

MAINTAINER=	sasaki@fcc.ad.jp
COMMENT=	Sendmail Sender Address Validator

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USERS=		smfs
GROUPS=		smfs

OPTIONS_DEFINE=	DOCS

USE_RC_SUBR=	smfsav

CPPFLAGS+=	-D_REENTRANT
LDFLAGS+=	-lmilter -lpthread

SMFSAV_RUN_DIR?=/var/run/smfs
PLIST_SUB=	SMFSAV_RUN_DIR=${SMFSAV_RUN_DIR}
SUB_FILES+=	pkg-message
SUB_LIST=	SMFSAV_RUN_DIR=${SMFSAV_RUN_DIR}

CONFLICTS=	smfsav

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/mail/sendmail/bsd.milter.mk"

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/readme
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/smf-sav.c
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/smf-sav.conf

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} ${CPPFLAGS} -o smf-sav smf-sav.c ${LDFLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/smf-sav ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/smf-sav.conf ${STAGEDIR}${PREFIX}/etc/smf-sav.conf.sample
	@${MKDIR} ${STAGEDIR}${SMFSAV_RUN_DIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ChangeLog readme ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
