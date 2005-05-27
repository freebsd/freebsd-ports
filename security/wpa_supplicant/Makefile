# New ports collection makefile for:	wpa_supplicant
# Date created:		7 December 2004
# Whom:			sam
#
# $FreeBSD$
#

# WITH_STATIC_SUPPLICANT - If you use wpa_supplicant with devd(8) to
#       start your wireless NIC at boot, it will not be able to resolve
#       the libdnet library dependency because devd is run before
#       ldconfig.  Defining this variable will get around the problem by
#       static-linking the wpa_supplicant executable.  A static-linked
#       version of the executable is about 1.25MB larger and you will be
#       required to rebuild this port whenever the net/libdnet port is
#       updated.

PORTNAME=	wpa_supplicant
PORTVERSION=	0.3.8
PORTREVISION=	2
CATEGORIES=	security net
MASTER_SITES=	http://hostap.epitest.fi/releases/

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	Supplicant (client) for WPA/802.1x protocols

LIB_DEPENDS=	dnet.1:${PORTSDIR}/net/libdnet

USE_REINPLACE=	yes

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

.if defined(WITH_STATIC_SUPPLICANT)
SUPPLICANT_STATIC=	-static
.else
SUPPLICANT_STATIC=
.endif
MAKE_ENV+=	SUPPLICANT_STATIC=${SUPPLICANT_STATIC}

post-patch:
	@${CP} ${FILESDIR}/config.bsd ${WRKSRC}/.config
	@${REINPLACE_CMD} 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/.config

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
