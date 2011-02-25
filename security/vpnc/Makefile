# New ports collection makefile for:	vpnc
# Date created:				15 December 2003
# Whom:					Christian Lackas
#
# $FreeBSD$
#

PORTNAME=	vpnc
PORTVERSION=	0.5.3
PORTREVISION=	4
CATEGORIES=	security
MASTER_SITES=	http://www.unix-ag.uni-kl.de/~massar/vpnc/ \
		CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Client for Cisco 3000 VPN Concentrator

LIB_DEPENDS=	gcrypt.17:${PORTSDIR}/security/libgcrypt

USE_GMAKE=	yes
USE_PERL5_BUILD=yes
USE_RC_SUBR=	vpnc
MAKE_JOBS_SAFE=	yes

ALL_TARGET=	all

PORTDOCS=	README TODO
MAN8=		vpnc.8

OPTIONS+=	DECRYPT       "cisco-decypt password decrypt utility"      on
OPTIONS+=	SSL           "OpenSSL certificate support (hybrid only)"  off
OPTIONS+=	CISCOVERSION  "Mask linux presentation string"             off

MAKE_ENV+=	LDFLAGS="${LDFLAGS}" BINS="${EXTRABUILDS}"

.include <bsd.port.pre.mk>

.if defined(WITH_DECRYPT)
MAN1=		cisco-decrypt.1
EXTRABUILDS+=	cisco-decrypt
PLIST_SUB+=	DECRYPT=""
.else
PLIST_SUB+=	DECRYPT="@comment "
.endif

.if defined(WITH_SSL)
NO_PACKAGE=	binary linked against OpenSSL must not be redistributed
CFLAGS+=	-DOPENSSL_GPL_VIOLATION
LDFLAGS+=	-lcrypto
.endif

.if defined(WITH_CISCOVERSION)
CFLAGS+=	-DCISCO_PATCH_VERSION
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/config.c
	@${REINPLACE_CMD} -e 's|\(/etc/vpnc\)|${PREFIX}\1|' \
		${WRKSRC}/${MAN8}.template

do-install:
	${INSTALL_PROGRAM} -m 751 ${WRKSRC}/vpnc ${PREFIX}/sbin/vpnc
.if defined(WITH_DECRYPT)
	${INSTALL_PROGRAM} ${WRKSRC}/cisco-decrypt ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MANPREFIX}/man/man1
.endif
	${INSTALL_SCRIPT} -m 751 ${WRKSRC}/vpnc-script ${PREFIX}/sbin/vpnc-script
	${INSTALL_SCRIPT} -m 751 ${WRKSRC}/vpnc-disconnect ${PREFIX}/sbin/vpnc-disconnect
	${INSTALL_DATA} -m 600 ${WRKSRC}/vpnc.conf ${PREFIX}/etc/vpnc.conf.sample
.if !exists(${PREFIX}/etc/vpnc.conf)
	${INSTALL_DATA} -m 600 ${WRKSRC}/vpnc.conf ${PREFIX}/etc
.endif
	${INSTALL_MAN} ${WRKSRC}/${MAN8} ${MANPREFIX}/man/man8

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
