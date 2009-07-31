# New ports collection makefile for:   openvpn-admin
# Date Created:                                06 Dec 2005
# Whom:                                        Remington Lang <MrL0Lz@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	openvpn-admin
PORTVERSION=	1.9.4
PORTREVISION=	2
CATEGORIES=	security gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GUI frontend to openvpn

RUN_DEPENDS=	openvpn:${PORTSDIR}/security/openvpn

WRKSRC=		${WRKDIR}/${DISTNAME:S/b//}

USE_GMAKE=	yes
USE_GNOME=	gtksharp20
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/bin/iconv,${LOCALBASE}/bin/iconv,g' \
		${WRKSRC}/intltool-merge.in
	@${REINPLACE_CMD} -e 's,/etc/openvpn,${PREFIX}/etc/openvpn,' \
		${WRKSRC}/src/Configuration.cs

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/openvpn-admin ${PREFIX}/sbin
	${MKDIR} ${PREFIX}/share/applications || ${TRUE}
	${INSTALL_DATA} ${WRKSRC}/openvpn-admin.desktop ${PREFIX}/share/applications/
	${MKDIR} ${PREFIX}/lib/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/src/openvpn-admin.exe ${PREFIX}/lib/${PORTNAME}
	${MKDIR} ${PREFIX}/etc/openvpn

.include <bsd.port.post.mk>
