# New ports collection makefile for:	vpnc
# Date created:				15 December 2003
# Whom:					Christian Lackas
#
# $FreeBSD$
#

PORTNAME=	vpnc
PORTVERSION=	0.4.0
PORTREVISION=	3
CATEGORIES=	security
MASTER_SITES=	http://www.unix-ag.uni-kl.de/~massar/vpnc/

MAINTAINER=	delta@lackas.net
COMMENT=	Client for Cisco 3000 VPN Concentrator

LIB_DEPENDS=	gcrypt.13:${PORTSDIR}/security/libgcrypt

USE_GMAKE=	yes
ALL_TARGET=	vpnc

USE_RC_SUBR=	vpnc
USE_PERL5_BUILD=	yes

PLIST_FILES=	sbin/vpnc \
		sbin/vpnc-script \
		sbin/vpnc-disconnect \
		etc/vpnc.conf.sample

PORTDOCS=	README TODO
MAN8=		vpnc.8

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/config.c
	@${REINPLACE_CMD} -e \
		's|%%PREFIX%%|${PREFIX}|;s|%%CC%%|${CC}|;s|%%CFLAGS%%|${CFLAGS}|' \
			${WRKSRC}/Makefile

do-install:
	@${INSTALL_PROGRAM} -m 751 ${WRKSRC}/vpnc ${PREFIX}/sbin/vpnc
	@${INSTALL_SCRIPT} -m 751 ${WRKSRC}/vpnc-script ${PREFIX}/sbin/vpnc-script
	@${INSTALL_SCRIPT} -m 751 ${WRKSRC}/vpnc-disconnect ${PREFIX}/sbin/vpnc-disconnect
	@${INSTALL_DATA} -m 600 ${WRKSRC}/vpnc.conf ${PREFIX}/etc/vpnc.conf.sample
.if !defined(NO_INSTALL_MANPAGES)
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/vpnc.8
	@${INSTALL_MAN} ${WRKSRC}/vpnc.8 ${PREFIX}/man/man8
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
