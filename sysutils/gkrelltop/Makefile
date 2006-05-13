# New ports collection makefile for:	gkrelltop
# Date created:				12 April 2004
# Whom:					David Gardner
#
# $FreeBSD$
#

PORTNAME=	gkrelltop
PORTVERSION=	2.2.6
PORTREVISION=	6
CATEGORIES=	sysutils
MASTER_SITES=	http://psychology.rutgers.edu/~zaimi/html/gkrelltop/
DISTNAME=	${PORTNAME}_2.2-6

MAINTAINER=	david@pinko.net
COMMENT=	Plugin for gkrellm 2.x shows top three processes, requires procfs

RUN_DEPENDS=	gkrellmd:${PORTSDIR}/sysutils/gkrellm2
BUILD_DEPENDS=	${RUN_DEPENDS}

USE_GMAKE=	yes
MAKE_ARGS=	INSTALLDIR=${X11BASE}/libexec/gkrellm2/plugins \
		INSTALLDIRD=${PREFIX}/libexec/gkrellm2/plugins-gkrellmd

.if defined(GKRELLM_SERVER_ONLY)
ALL_TARGET=	server
INSTALL_TARGET=	install-server
PLIST_SUB+=	CLIENT="@comment "
.else
PLIST_SUB+=	CLIENT=""
.endif

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-patch:
.if defined(GKRELLM_SERVER_ONLY)
	${REINPLACE_CMD} 's/^\(PKG.*\)gkrellm/\1gkrellmd/' ${WRKSRC}/configure
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
