# New ports collection makefile for:	vpnc
# Date created:				15 December 2003
# Whom:					Christian Lackas
#
# $FreeBSD$
#

PORTNAME=	vpnc
PORTVERSION=	0.3.3
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.unix-ag.uni-kl.de/~massar/vpnc/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	delta@lackas.net
COMMENT=	Client for Cisco 3000 VPN Concentrator

LIB_DEPENDS=	gcrypt.13:${PORTSDIR}/security/libgcrypt

STARTSCRIPT=	vpnc-wrapper-1.25
USE_GMAKE=	yes
USE_REINPLACE=	yes
ALL_TARGET=	vpnc

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
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/ChangeLog ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/TODO ${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
