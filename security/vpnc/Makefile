# New ports collection makefile for:	vpnc
# Date created:				15 December 2003
# Whom:					Christian Lackas
#
# $FreeBSD$
#

PORTNAME=	vpnc
PORTVERSION=	0.2
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://www.unix-ag.uni-kl.de/~massar/vpnc/
DISTNAME=	${PORTNAME}-${PORTVERSION}-rm+zomb-pre7

MAINTAINER=	delta@lackas.net
COMMENT=	Client for Cisco 3000 VPN Concentrator

LIB_DEPENDS=	gcrypt.10:${PORTSDIR}/security/libgcrypt-devel

USE_GMAKE=	yes
USE_REINPLACE=	yes
ALL_TARGET=	vpnc

MAN8=		vpnc.8

post-patch:
	@${REINPLACE_CMD} -e \
		's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/vpnc.c
	@${REINPLACE_CMD} -e \
		's|%%CC%%|${CC}|;s|%%CFLAGS%%|${CFLAGS}|' \
			${WRKSRC}/Makefile

do-install:
	@${INSTALL_PROGRAM} -m 751 ${WRKSRC}/vpnc ${PREFIX}/sbin/vpnc
	@${INSTALL_SCRIPT} -m 755 ${FILESDIR}/vpnc.sh ${PREFIX}/etc/rc.d/vpnc.sh.sample
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' \
				${PREFIX}/etc/rc.d/vpnc.sh.sample
	@${INSTALL_DATA} -m 600 ${WRKSRC}/vpnc.conf ${PREFIX}/etc/vpnc.conf.sample
.if !defined(NO_INSTALL_MANPAGES)
	@${INSTALL_MAN} ${FILESDIR}/vpnc.8 ${PREFIX}/man/man8
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/ChangeLog ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/TODO ${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
