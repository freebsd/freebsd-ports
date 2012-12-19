# Created by: Olivier Cochard-Labbe <olivier@cochard.me>
# $FreeBSD$

PORTNAME=	surfer
PORTVERSION=	0.2.6
CATEGORIES=	www
MASTER_SITES=	http://www.defora.org/os/download/download/3709/
DISTNAME=	Surfer-${PORTVERSION}
PKGNAMEPREFIX=	deforaos-

MAINTAINER=	olivier@cochard.me
COMMENT=	DeforaOS desktop web browser

LICENSE=	GPLv3

BUILD_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt \
		${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:${PORTSDIR}/textproc/docbook-xsl
LIB_DEPENDS=	System:${PORTSDIR}/devel/deforaos-libsystem \
		Desktop:${PORTSDIR}/x11/deforaos-libdesktop \
		gnet-2.0:${PORTSDIR}/net/gnet2 \
		webkitgtk-1.0:${PORTSDIR}/www/webkit-gtk2
RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss

USE_GNOME=	gtk20 desktopfileutils
USE_PKGCONFIG=	build
USE_GETTEXT=	yes
INSTALLS_ICONS=	yes

MAKE_ENV+=	MANDIR=${MANPREFIX}/man

MAN1=		download.1 helper.1 surfer.1

.include <bsd.port.mk>
