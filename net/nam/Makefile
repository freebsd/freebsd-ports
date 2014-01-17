# Created by: obonilla
# $FreeBSD$

PORTNAME=	nam
PORTVERSION=	1.15
CATEGORIES=	net
MASTER_SITES=	SF/ns${PORTNAME}/${PORTNAME}-1/${PORTVERSION}
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	masaki@club.kyutech.ac.jp
COMMENT=	Animation tool for network simulation traces

BUILD_DEPENDS=	${LOCALBASE}/lib/libtclcl.a:${PORTSDIR}/devel/tclcl
LIB_DEPENDS=	libotcl.so:${PORTSDIR}/lang/otcl

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		gmake tk:85+
USE_XORG=	xmu
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tcl-ver=${TCL_VER} --with-tk-ver=${TK_VER} --x-libraries=${LOCALBASE}/lib --x-includes=${LOCALBASE}/include
ALL_TARGET=	${PORTNAME}

OPTIONS_DEFINE=	EXAMPLES

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e "s,%%LOCALBASE%%,${LOCALBASE},g" \
		${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nam ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/nam.1 ${STAGEDIR}${PREFIX}/man/man1
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/ex/* ${STAGEDIR}${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
