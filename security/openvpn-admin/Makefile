# New ports collection makefile for:   openvpn-admin
# Date Created:                                06 Dec 2005
# Whom:                                        Remington Lang <MrL0Lz@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	openvpn-admin
PORTVERSION=	1.9.2
PORTREVISION=	2
CATEGORIES=	security gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	openvpnadmin

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
BROKEN=	"Some dependencies doesn't build on FreeBSD < 5.x"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/bin/iconv,${LOCALBASE}/bin/iconv,g' \
		${WRKSRC}/intltool-merge.in

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/openvpn-admin ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/openvpn-admin.pam ${PREFIX}/etc/pam.d
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/openvpn-admin.desktop ${DATADIR}

.include <bsd.port.post.mk>
