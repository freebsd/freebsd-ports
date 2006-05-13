# New ports collection makefile for:	vpnc
# Date created:				15 December 2003
# Whom:					Christian Lackas
#
# $FreeBSD$
#

PORTNAME=	vpnc
PORTVERSION=	0.3.3
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://www.unix-ag.uni-kl.de/~massar/vpnc/

MAINTAINER=	delta@lackas.net
COMMENT=	Client for Cisco 3000 VPN Concentrator

LIB_DEPENDS=	gcrypt.13:${PORTSDIR}/security/libgcrypt

USE_GMAKE=	yes
ALL_TARGET=	vpnc

PLIST_FILES=	sbin/vpnc \
		sbin/vpnc-script \
		sbin/vpnc-disconnect \
		etc/vpnc.conf.sample \
		etc/rc.d/vpnc.sh.sample

PORTDOCS=	README ChangeLog TODO
MAN8=		vpnc.8

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/config.c
	@${REINPLACE_CMD} -e \
		's|%%CC%%|${CC}|;s|%%CFLAGS%%|${CFLAGS}|' \
			${WRKSRC}/Makefile

do-install:
	@${INSTALL_PROGRAM} -m 751 ${WRKSRC}/vpnc ${PREFIX}/sbin/vpnc
	@${INSTALL_SCRIPT} -m 751 ${WRKSRC}/vpnc-script ${PREFIX}/sbin/vpnc-script
	@${INSTALL_SCRIPT} -m 751 ${WRKSRC}/vpnc-disconnect ${PREFIX}/sbin/vpnc-disconnect
	@${INSTALL_SCRIPT} ${FILESDIR}/vpnc.sh ${WRKDIR}
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' ${WRKDIR}/vpnc.sh
	@${INSTALL_SCRIPT} -m 755 ${WRKDIR}/vpnc.sh ${PREFIX}/etc/rc.d/vpnc.sh.sample
	@${INSTALL_DATA} -m 600 ${WRKSRC}/vpnc.conf ${PREFIX}/etc/vpnc.conf.sample
.if !defined(NO_INSTALL_MANPAGES)
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/vpnc.8
	@${INSTALL_MAN} ${WRKSRC}/vpnc.8 ${PREFIX}/man/man8
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
