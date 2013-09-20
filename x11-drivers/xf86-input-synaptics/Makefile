# $FreeBSD$

PORTNAME=	xf86-input-synaptics
PORTVERSION=	${SYNAPTICS_VERSION}
PORTREVISION=	${SYNAPTICS_REVISION}
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org synaptics input driver

CONFLICTS=	synaptics-[0-9]*

OPTIONS_DEFINE=	HAL
OPTIONS_DEFAULT=HAL

NO_STAGE=	yes
.include <bsd.port.options.mk>

USES=		pathfix
USE_XORG=	x11
XORG_CAT=	driver

.if ${PORT_OPTIONS:MHAL}
PLIST_SUB+=	HAL=""
LIB_DEPENDS+=	hal.1:${PORTSDIR}/sysutils/hal
.else
PLIST_SUB+=	HAL="@comment "
.endif

MAN1=		syndaemon.1 \
		synclient.1
MAN4=		synaptics.4x

.if defined(WITH_NEW_XORG)
SYNAPTICS_VERSION=	1.7.1
SYNAPTICS_REVISION=	0
PLIST_SUB+=	NEW="" OLD="@comment "
.else
SYNAPTICS_VERSION=	1.6.4
SYNAPTICS_REVISION=	0
PLIST_SUB+=	NEW="@comment " OLD=""
EXTRA_PATCHES+=	${PATCHDIR}/extra-Makefile.in
.endif

post-install:
.if ${PORT_OPTIONS:MHAL}
	${MKDIR} ${PREFIX}/share/hal/fdi/policy/10osvendor
	${INSTALL_DATA} ${WRKSRC}/conf/11-x11-synaptics.fdi \
		${PREFIX}/share/hal/fdi/policy/10osvendor/
.if !defined(WITH_NEW_XORG)
	${MKDIR} ${PREFIX}/share/hal/fdi/policy/20thirdparty
	${INSTALL_DATA} ${WRKSRC}/conf/11-x11-synaptics.fdi \
		${PREFIX}/share/hal/fdi/policy/20thirdparty/
.endif
.endif

.include <bsd.port.mk>
