# New ports collection makefile for:	wpa_supplicant
# Date created:		7 December 2004
# Whom:			sam
#
# $FreeBSD$
#

PORTNAME=	wpa_supplicant
PORTVERSION=	0.3.0
PORTREVISION=	1
CATEGORIES=	security net
MASTER_SITES=	http://hostap.epitest.fi/releases/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Supplicant (client) for WPA/802.1x protocols

BUILD_DEPENDS=	${LOCALBASE}/lib/libdnet.a:${PORTSDIR}/net/libdnet

PLIST_FILES=	bin/wpa_supplicant \
		bin/wpa_passphrase \
		bin/wpa_cli

.if !defined(NOPORTDOCS)
DOCFILES=	README \
		ChangeLog \
		wpa_supplicant.conf
PLIST_FILES+=	${DOCFILES:S,^,%%DOCSDIR%%/,}
PLIST_DIRS+=	%%DOCSDIR%%
.endif

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_GMAKE=	yes

post-extract:
	@${CP} ${FILESDIR}/config.bsd ${WRKSRC}/.config

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${DOCFILES:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 600007
IGNORE=is not supported on FreeBSD < 6.0
.endif

.include <bsd.port.post.mk>
