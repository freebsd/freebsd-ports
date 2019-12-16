# Created by: Christian Lackas
# $FreeBSD$

PORTNAME=	vpnc
PORTVERSION=	0.5.3
PORTREVISION=	14
CATEGORIES=	security net-vpn
MASTER_SITES=	http://www.unix-ag.uni-kl.de/~massar/vpnc/ \
		LOCAL/ehaupt

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Client for Cisco 3000 VPN Concentrator

LICENSE=	BSD2CLAUSE GPLv2+
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
		libgpg-error.so:security/libgpg-error
RUN_DEPENDS=	vpnc-script:sysutils/vpnc-scripts

USES=		gmake perl5 shebangfix
USE_PERL5=	build
USE_RC_SUBR=	vpnc

LEGAL_TEXT=	Redistribution is not allowed if linked against OpenSSL

ALL_TARGET=	all
SHEBANG_FILES=	makeman.pl

PORTDOCS=	README TODO

MAKE_ENV=	BINS="${EXTRABUILDS}"

OPTIONS_DEFINE=		CISCOVERSION DECRYPT DOCS SSL
OPTIONS_DEFAULT=	DECRYPT
OPTIONS_SUB=		yes

CISCOVERSION_DESC=	Mask linux presentation string
CISCOVERSION_CFLAGS=	-DCISCO_PATCH_VERSION

DECRYPT_DESC=	cisco-decypt password decrypt utility
DECRYPT_VARS=	EXTRABUILDS+=cisco-decrypt

SSL_VARS=	NO_PACKAGE="binary linked against OpenSSL must not be redistributed"
SSL_CFLAGS=	-DOPENSSL_GPL_VIOLATION
SSL_LDFLAGS=	-lcrypto

post-patch:
	@${REINPLACE_CMD} \
		-e 's|.*%%FREEBSD_IPLEN_FIX%%.*|#define NEED_IPLEN_FIX 1|' \
		${WRKSRC}/sysdep.h
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/config.c
	@${REINPLACE_CMD} -e 's|\(/etc/vpnc\)|${PREFIX}\1|' \
		${WRKSRC}/vpnc.8.template

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vpnc ${STAGEDIR}${PREFIX}/sbin/vpnc
	${INSTALL_SCRIPT} ${WRKSRC}/vpnc-disconnect \
		${STAGEDIR}${PREFIX}/sbin/vpnc-disconnect
	${INSTALL_DATA} ${WRKSRC}/vpnc.conf \
		${STAGEDIR}${PREFIX}/etc/vpnc.conf.sample
	${INSTALL_MAN} ${WRKSRC}/vpnc.8 ${STAGEDIR}${MANPREFIX}/man/man8

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

do-install-DECRYPT-on:
	${INSTALL_PROGRAM} ${WRKSRC}/cisco-decrypt ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/cisco-decrypt.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
