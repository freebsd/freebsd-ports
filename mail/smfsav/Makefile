# Created by: Anton Lysenok <bart@tapolsky.net.ua>
# $FreeBSD$

PORTNAME=	smfsav
PORTVERSION=	1.4.0
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	SF/smfs
DISTNAME=	smf-sav-${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sendmail Sender Address Validator

LICENSE=	GPLv2

OPTIONS_DEFINE=	DOCS

USE_RC_SUBR=	smfsav

CPPFLAGS+=	-D_REENTRANT ${PTHREAD_CFLAGS}
LDFLAGS+=	-lmilter ${PTHREAD_LIBS}

SUB_FILES=	pkg-message

PORTDOCS=	CHANGES README
PLIST_FILES=	sbin/smfsav \
		etc/smfsav.conf-dist

NO_STAGE=	yes
.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/readme

do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} ${CPPFLAGS} -o smf-sav smf-sav.c \
		${LDFLAGS})

do-install:
	(cd ${WRKSRC} \
		&& ${INSTALL_PROGRAM} smf-sav ${PREFIX}/sbin/smfsav \
		&& ${INSTALL_DATA} smf-sav.conf ${PREFIX}/etc/smfsav.conf-dist)
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC} \
		&& ${INSTALL_DATA} ChangeLog ${DOCSDIR}/CHANGES \
		&& ${INSTALL_DATA} readme ${DOCSDIR}/README)
.endif
	${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
