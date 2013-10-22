# Created by: Remington Lang <MrL0Lz@gmail.com>
# $FreeBSD$

PORTNAME=	openvpn-admin
PORTVERSION=	1.9.4
PORTREVISION=	5
CATEGORIES=	security gnome
MASTER_SITES=	SF/${PORTNAME}/OldFiles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GUI frontend to openvpn

RUN_DEPENDS=	openvpn:${PORTSDIR}/security/openvpn

WRKSRC=		${WRKDIR}/${DISTNAME:S/b//}

USES=		gmake pkgconfig
USE_GNOME=	gtksharp20
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

NO_STAGE=	yes
.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/bin/iconv,${LOCALBASE}/bin/iconv,g' \
		${WRKSRC}/intltool-merge.in
	@${REINPLACE_CMD} -e 's,/etc/openvpn,${PREFIX}/etc/openvpn,' \
		${WRKSRC}/src/Configuration.cs

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/openvpn-admin ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/openvpn-admin.desktop ${PREFIX}/share/applications/
	${MKDIR} ${PREFIX}/lib/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/src/openvpn-admin.exe ${PREFIX}/lib/${PORTNAME}
	${MKDIR} ${PREFIX}/etc/openvpn

.include <bsd.port.post.mk>
