# Created by: Christian Lackas
# $FreeBSD$

PORTNAME=	vpnc
PORTVERSION=	0.5.3
PORTREVISION=	7
CATEGORIES=	security
MASTER_SITES=	http://www.unix-ag.uni-kl.de/~massar/vpnc/ \
		CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Client for Cisco 3000 VPN Concentrator

LIB_DEPENDS=	gcrypt.18:${PORTSDIR}/security/libgcrypt
RUN_DEPENDS=	vpnc-script:${PORTSDIR}/sysutils/vpnc-scripts

USE_GMAKE=	yes
USE_PERL5_BUILD=yes
USE_RC_SUBR=	vpnc
MAKE_JOBS_SAFE=	yes

ALL_TARGET=	all

PORTDOCS=	README TODO
MAN8=		vpnc.8

MAKE_ENV+=	BINS="${EXTRABUILDS}"

OPTIONS_DEFINE=	DECRYPT SSL CISCOVERSION DOCS

DECRYPT_DESC=		cisco-decypt password decrypt utility
CISCOVERSION_DESC=	Mask linux presentation string

OPTIONS_DEFAULT=DECRYPT

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDECRYPT}
MAN1=		cisco-decrypt.1
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
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/config.c
	@${REINPLACE_CMD} -e 's|\(/etc/vpnc\)|${PREFIX}\1|' \
		${WRKSRC}/${MAN8}.template
	@${REINPLACE_CMD} -e '1s|.*perl|#!${PERL}|' ${WRKSRC}/makeman.pl

do-install:
	${INSTALL_PROGRAM} -m 751 ${WRKSRC}/vpnc ${PREFIX}/sbin/vpnc
.if ${PORT_OPTIONS:MDECRYPT}
	${INSTALL_PROGRAM} ${WRKSRC}/cisco-decrypt ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MANPREFIX}/man/man1
.endif
	${INSTALL_SCRIPT} -m 751 ${WRKSRC}/vpnc-disconnect ${PREFIX}/sbin/vpnc-disconnect
	${INSTALL_DATA} -m 600 ${WRKSRC}/vpnc.conf ${PREFIX}/etc/vpnc.conf.sample
.if !exists(${PREFIX}/etc/vpnc.conf)
	${INSTALL_DATA} -m 600 ${WRKSRC}/vpnc.conf ${PREFIX}/etc
.endif
	${INSTALL_MAN} ${WRKSRC}/${MAN8} ${MANPREFIX}/man/man8

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
