# Created by: Remington Lang <MrL0Lz@gmail.com>
# $FreeBSD$

PORTNAME=	openvpn-admin
PORTVERSION=	1.9.4
DISTVERSIONSUFFIX=	-2
PORTREVISION=	6
CATEGORIES=	security gnome net-vpn
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/release-${PORTVERSION}

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	GUI frontend to openvpn

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	openvpn:security/openvpn

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

NO_ARCH=	yes
PORTSCOUT=	skipv:${PORTVERSION}${DISTVERSIONSUFFIX}

USES=		gettext gmake gnome pkgconfig
USE_GNOME=	gtksharp20 intltool
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/bin/iconv,${LOCALBASE}/bin/iconv,g' \
		${WRKSRC}/intltool-merge.in
	@${REINPLACE_CMD} -e 's,/etc/openvpn,${PREFIX}/etc/openvpn,' \
		${WRKSRC}/src/Configuration.cs

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/openvpn-admin ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/openvpn-admin.desktop \
		${STAGEDIR}${PREFIX}/share/applications
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/src/openvpn-admin.exe \
		${STAGEDIR}${PREFIX}/lib/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/openvpn

.include <bsd.port.mk>
