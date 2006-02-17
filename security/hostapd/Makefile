# New ports collection makefile for:	hostapd
# Date created:		7 December 2004
# Whom:			sam
#
# $FreeBSD$
#

PORTNAME=	hostapd
PORTVERSION=	0.4.8
CATEGORIES=	security
MASTER_SITES=	http://hostap.epitest.fi/releases/ \
		http://www.freebsdbrasil.com.br/~jmelo/

MAINTAINER=	jmelo@freebsdbrasil.com.br
COMMENT=	Authenticator (server) for WPA/802.1x protocols

LIB_DEPENDS=	dnet.1:${PORTSDIR}/net/libdnet

USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}
MAKE_ENV+=	CC="${CC}"
CFLAGS+=	-DCONFIG_DRIVER_BSD

PLIST_FILES=	bin/hostapd bin/hostapd_cli

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 600007
IGNORE=is not supported on FreeBSD < 6.0
.endif

post-extract:
	@${TOUCH} ${WRKSRC}/.config

post-patch:
	@${REINPLACE_CMD} -e '/^CC/d' ${WRKSRC}/${MAKEFILE}

.include <bsd.port.post.mk>
