# New ports collection makefile for:	qmail-dk
# Date created:		2006-07-18
# Whom:			Renato Botelho <garga@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dk
PORTVERSION=	0.54
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_QMAIL}
PKGNAMEPREFIX=	qmail-
DISTFILES=	qmail-1.03.tar.gz
DIST_SUBDIR=	qmail

MAINTAINER=	garga@FreeBSD.org
COMMENT=	DomainKeys implementation for qmail

LIB_DEPENDS+=	domainkeys.3:${PORTSDIR}/mail/libdomainkeys

PATCH_SITES=	${MASTER_SITE_QMAIL}
PATCHFILES=	qmail-1.03-dk-0.54.patch

USE_QMAIL=	yes
MAKE_JOBS_SAFE=	yes
PREFIX?=	${QMAIL_PREFIX}

WRKSRC=		${WRKDIR}/qmail-1.03
PLIST_FILES=	bin/qmail-dk
MAN8=		qmail-dk.8
ALL_TARGET=	qmail-dk ${MAN8}
CFLAGS+=	-I${LOCALBASE}/include

OPTIONS=	SMTP_AUTH "Support SMTP_AUTH" On

.include <bsd.port.pre.mk>

.if defined(WITH_SMTP_AUTH)
PATCH_SITES+=	http://jeremy.kister.net/code/:auth
PATCHFILES+=	qmail-dk-0.54-auth.patch:auth
.endif

do-configure:
	@${ECHO_CMD} "${CC} ${CFLAGS}" > ${WRKSRC}/conf-cc
	@${ECHO_CMD} ${PREFIX} > ${WRKSRC}/conf-qmail

post-patch:
	@${REINPLACE_CMD} -e 's,"../domainkeys.h",<domainkeys.h>,' \
		${WRKSRC}/qmail-dk.c
	@${REINPLACE_CMD} -e 's,../libdomainkeys.a,${LOCALBASE}/lib/libdomainkeys.a,g' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -E 's|( *c\(auto.*")qmail-smtpd(".*)$$|\1qmail-smtpd\2\1qmail-dk\2|' \
		${WRKSRC}/hier.c
	@${REINPLACE_CMD} 's!/var/qmail!${PREFIX}!; \
			   s!/usr/local/!${LOCALBASE}/!' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} 's!nofiles!qnofiles!g' \
		${WRKSRC}/conf-groups

do-install:
	${INSTALL} -o qmailq -m 4711 ${WRKSRC}/qmail-dk ${PREFIX}/bin
.for m in ${MAN8}
	${INSTALL_MAN} ${WRKSRC}/${m} ${MAN8PREFIX}/man/man8
.endfor

.include <bsd.port.post.mk>
