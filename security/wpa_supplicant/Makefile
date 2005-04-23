# New ports collection makefile for:	wpa_supplicant
# Date created:		7 December 2004
# Whom:			sam
#
# $FreeBSD$
#

PORTNAME=	wpa_supplicant
PORTVERSION=	0.3.8
PORTREVISION=	1
CATEGORIES=	security net
MASTER_SITES=	http://hostap.epitest.fi/releases/

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	Supplicant (client) for WPA/802.1x protocols

USE_REINPLACE=	yes

BUILD_DEPENDS=	${LOCALBASE}/lib/libdnet.a:${PORTSDIR}/net/libdnet

PLIST_FILES=	sbin/wpa_supplicant \
		sbin/wpa_passphrase \
		sbin/wpa_cli

PLIST_FILES+=	etc/${PORTNAME}.conf.sample

.if !defined(NOPORTDOCS)
DOCFILES=	README \
		ChangeLog
PLIST_FILES+=	${DOCFILES:S,^,%%DOCSDIR%%/,}
PLIST_DIRS+=	%%DOCSDIR%%
.endif

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_GMAKE=	yes

post-patch:
	@${CP} ${FILESDIR}/config.bsd ${WRKSRC}/.config
	@${REINPLACE_CMD} 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/.config
	@${REINPLACE_CMD} 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${DOCFILES:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif
	@${INSTALL_DATA} ${WRKSRC}/wpa_supplicant.conf ${PREFIX}/etc/wpa_supplicant.conf.sample

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 600007
IGNORE=is not supported on FreeBSD < 6.0
.endif

.include <bsd.port.post.mk>
