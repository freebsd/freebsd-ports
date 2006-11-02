# New ports collection makefile for:   openvpn-admin
# Date Created:                                06 Dec 2005
# Whom:                                        Remington Lang <MrL0Lz@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	openvpn-admin
PORTVERSION=	1.9.2
PORTREVISION=	3
CATEGORIES=	security gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	MrL0Lz@gmail.com
COMMENT=	GUI frontend to openvpn

BUILD_DEPENDS=	mono:${PORTSDIR}/lang/mono \
		gapi2-codegen:${PORTSDIR}/x11-toolkits/gtk-sharp20
RUN_DEPENDS=	mono:${PORTSDIR}/lang/mono \
		gapi2-codegen:${PORTSDIR}/x11-toolkits/gtk-sharp20 \
		openvpn:${PORTSDIR}/security/openvpn

USE_GMAKE=	yes
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=	Some dependencies don't build on FreeBSD < 5.x
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/bin/iconv,${LOCALBASE}/bin/iconv,g' \
		${WRKSRC}/intltool-merge.in
	@${REINPLACE_CMD} -e 's,/etc/openvpn,${PREFIX}/etc/openvpn,' \
		${WRKSRC}/src/Configuration.cs

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/openvpn-admin ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/openvpn-admin.pam ${PREFIX}/etc/pam.d/openvpn-admin
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/openvpn-admin.desktop ${DATADIR}
	${MKDIR} ${PREFIX}/lib/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/src/openvpn-admin.exe ${PREFIX}/lib/${PORTNAME}
	${MKDIR} ${PREFIX}/etc/openvpn

.include <bsd.port.post.mk>
