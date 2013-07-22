# Whom: David Gardner
# $FreeBSD$

PORTNAME=	gkrelltop
PORTVERSION=	2.2.10
CATEGORIES=	sysutils
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	david@pinko.net
COMMENT=	Plugin for gkrellm 2.x shows top three processes, requires procfs

RUN_DEPENDS=	gkrellmd:${PORTSDIR}/sysutils/gkrellm2
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		gmake
MAKE_ARGS=	INSTALLDIR=${LOCALBASE}/libexec/gkrellm2/plugins \
		INSTALLDIRD=${PREFIX}/libexec/gkrellm2/plugins-gkrellmd

.if defined(GKRELLM_SERVER_ONLY)
ALL_TARGET=	server
INSTALL_TARGET=	install-server
PLIST_SUB+=	CLIENT="@comment "
.else
PLIST_SUB+=	CLIENT=""
.endif

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}

post-patch:
.if defined(GKRELLM_SERVER_ONLY)
	${REINPLACE_CMD} 's/^\(PKG.*\)gkrellm/\1gkrellmd/' ${WRKSRC}/configure
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
