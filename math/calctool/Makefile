# Created by: nsayer@quack.kfu.com
# $FreeBSD$

PORTNAME=	calctool
PORTVERSION=	2.4.13
PORTREVISION=	5
CATEGORIES=	math
MASTER_SITES=	LOCAL/nsayer
DISTNAME=	calctool-2.4pl13

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multi-GUI (terminal, X, XView) calculator program

USE_LDCONFIG=	yes

OPTIONS_DEFINE=	X11 TTY XVIEW
OPTIONS_DEFAULT=	X11 TTY
X11_DESC=	Build X11 version of calctool
TTY_DESC=	Build tty version of calctool
XVIEW_DESC=	Build tty version of calctool

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MX11}
USE_XORG=	x11
BINARIES+=	xcalctool
PLIST_SUB+=	X11=""
.else
PLIST_SUB+=	X11="@comment "
.endif

.if ${PORT_OPTIONS:MTTY}
BINARIES+=	tty_calctool
PLIST_SUB+=	TTY=""
.else
PLIST_SUB+=	TTY="@comment "
.endif

.if ${PORT_OPTIONS:MXVIEW}
BINARIES+=	xv_calctool
LIB_DEPENDS+=	libxview.so:${PORTSDIR}/x11-toolkits/xview
PLIST_SUB+=	XVIEW=""
.else
PLIST_SUB+=	XVIEW="@comment "
.endif

.if ${ARCH} == "sparc64"
FPIC=	-fPIC
.else
FPIC=	-fpic
.endif

post-patch:
	@${REINPLACE_CMD}	-e "s#%%FPIC%%#${FPIC}#g" \
				-e "s#%%LOCALBASE%%#${LOCALBASE}#g" \
				-e "s#%%BINARIES%%#${BINARIES}#g" \
				-e "s#%%DATADIR%%#${DATADIR}#g" \
				${WRKSRC}/Makefile

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/libcalctool.so.1 ${STAGEDIR}${PREFIX}/lib
	@(cd ${STAGEDIR}${PREFIX}/lib; ${LN} -sf libcalctool.so.1 libcalctool.so)
.for BIN in ${BINARIES}
	${INSTALL_PROGRAM} ${WRKSRC}/${BIN} ${STAGEDIR}${PREFIX}/bin
.endfor
	${INSTALL_MAN} ${WRKSRC}/calctool.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/calctool.help ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
