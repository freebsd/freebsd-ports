# New ports collection makefile for:	vpnc
# Date created:			        15 December 2003
# Whom:                			Christian Lackas
#
# $FreeBSD$
#

PORTNAME=	vpnc
PORTVERSION=	0.2
CATEGORIES=	security
MASTER_SITES=	http://www.unix-ag.uni-kl.de/~massar/vpnc/
DISTNAME=	${PORTNAME}-${PORTVERSION}-rm+zomb-pre6

MAINTAINER=	delta@lackas.net
COMMENT=	"Client for Cisco 3000 VPN Concentrator"

LIB_DEPENDS=	gcrypt.6:${PORTSDIR}/security/libgcrypt

USE_GMAKE=	yes
ALL_TARGET=	vpnc
INSTALL_TARGET=

post-install:
	@${INSTALL_PROGRAM} -m 751 ${WRKSRC}/vpnc ${PREFIX}/sbin/vpnc
	@${INSTALL_SCRIPT} -m 755 ${FILESDIR}/vpnc.sh ${PREFIX}/etc/rc.d/vpnc.sh.sample
	@${INSTALL_DATA} -m 600 ${WRKSRC}/vpnc.conf ${PREFIX}/etc/vpnc.conf.sample
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} -m 666 ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
