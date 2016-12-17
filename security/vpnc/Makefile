# Created by: Christian Lackas
# $FreeBSD$

PORTNAME=	vpnc
PORTVERSION=	0.5.3
PORTREVISION=	12
CATEGORIES=	security
MASTER_SITES=	http://www.unix-ag.uni-kl.de/~massar/vpnc/ \
		LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Client for Cisco 3000 VPN Concentrator

LICENSE=	GPLv2 BSD2CLAUSE
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
		libgpg-error.so:security/libgpg-error
RUN_DEPENDS=	vpnc-script:sysutils/vpnc-scripts

USES=		shebangfix gmake perl5
USE_PERL5=	build
USE_RC_SUBR=	vpnc

LEGAL_TEXT=	Redistribution is not allowed if linked against OpenSSL

ALL_TARGET=	all
SHEBANG_FILES=	makeman.pl

PORTDOCS=	README TODO
MANPAGE8=	vpnc.8

MAKE_ENV+=	BINS="${EXTRABUILDS}"

OPTIONS_DEFINE=	DECRYPT SSL CISCOVERSION DOCS

DECRYPT_DESC=		cisco-decypt password decrypt utility
CISCOVERSION_DESC=	Mask linux presentation string

OPTIONS_DEFAULT=DECRYPT

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDECRYPT}
MANPAGE1=	cisco-decrypt.1
EXTRABUILDS+=	cisco-decrypt
PLIST_SUB+=	DECRYPT=""
.else
PLIST_SUB+=	DECRYPT="@comment "
.endif

.if ${PORT_OPTIONS:MSSL}
NO_PACKAGE=	binary linked against OpenSSL must not be redistributed
CFLAGS+=	-DOPENSSL_GPL_VIOLATION
LDFLAGS+=	-lcrypto
.endif

.if ${PORT_OPTIONS:MCISCOVERSION}
CFLAGS+=	-DCISCO_PATCH_VERSION
.endif

post-patch:
.if ${OSVERSION} >= 1100042
	@${REINPLACE_CMD} \
		-e 's|.*%%FREEBSD_IPLEN_FIX%%.*|#define NEED_IPLEN_FIX 1|' \
		${WRKSRC}/sysdep.h
.endif
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/config.c
	@${REINPLACE_CMD} -e 's|\(/etc/vpnc\)|${PREFIX}\1|' \
		${WRKSRC}/${MANPAGE8}.template

do-install:
	${INSTALL_PROGRAM} -m 751 ${WRKSRC}/vpnc ${STAGEDIR}${PREFIX}/sbin/vpnc
.if ${PORT_OPTIONS:MDECRYPT}
	${INSTALL_PROGRAM} ${WRKSRC}/cisco-decrypt ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MANPAGE1} ${STAGEDIR}${MANPREFIX}/man/man1
.endif
	${INSTALL_SCRIPT} -m 751 ${WRKSRC}/vpnc-disconnect \
		${STAGEDIR}${PREFIX}/sbin/vpnc-disconnect
	${INSTALL_DATA} -m 600 ${WRKSRC}/vpnc.conf \
		${STAGEDIR}${PREFIX}/etc/vpnc.conf.sample
.if !exists(${STAGEDIR}${PREFIX}/etc/vpnc.conf)
	${INSTALL_DATA} -m 600 ${WRKSRC}/vpnc.conf ${STAGEDIR}${PREFIX}/etc
.endif
	${INSTALL_MAN} ${WRKSRC}/${MANPAGE8} ${STAGEDIR}${MANPREFIX}/man/man8
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
