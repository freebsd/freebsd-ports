# $FreeBSD$

PORTNAME=	dk
PORTVERSION=	0.54
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	QMAIL
PKGNAMEPREFIX=	qmail-
DISTFILES=	qmail-1.03.tar.gz
DIST_SUBDIR=	qmail

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DomainKeys implementation for qmail

LIB_DEPENDS+=	libdomainkeys.so:mail/libdomainkeys

PATCH_SITES=	QMAIL
PATCHFILES=	qmail-1.03-dk-0.54.patch

USES=		qmail

PREFIX?=	${QMAIL_PREFIX}

WRKSRC=		${WRKDIR}/qmail-1.03
PLIST_FILES=	"@(qmailq,,4711) bin/qmail-dk" \
		man/man8/qmail-dk.8.gz
ALL_TARGET=	qmail-dk qmail-dk.8
CFLAGS+=	-I${LOCALBASE}/include

OPTIONS_DEFINE=	SMTP_AUTH
OPTIONS_DEFAULT=SMTP_AUTH

SMTP_AUTH_DESC=	Support SMTP_AUTH

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSMTP_AUTH}
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
	${INSTALL_PROGRAM} ${WRKSRC}/qmail-dk ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/qmail-dk.8 ${STAGEDIR}${MAN8PREFIX}/man/man8

.include <bsd.port.mk>
