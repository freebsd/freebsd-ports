# Created by: Olivier Cochard-Labbe <olivier@cochard.me>
# $FreeBSD$

PORTNAME=	surfer
PORTVERSION=	0.2.7
CATEGORIES=	www
MASTER_SITES=	http://www.defora.org/os/download/download/4345/
PKGNAMEPREFIX=	deforaos-
DISTNAME=	Surfer-${PORTVERSION}

MAINTAINER=	olivier@cochard.me
COMMENT=	DeforaOS desktop web browser

LICENSE=	GPLv3

BUILD_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt \
		docbook-xsl>=0:${PORTSDIR}/textproc/docbook-xsl
LIB_DEPENDS=	libSystem.so:${PORTSDIR}/devel/deforaos-libsystem \
		libDesktop.so:${PORTSDIR}/x11/deforaos-libdesktop \
		libgnet-2.0.so:${PORTSDIR}/net/gnet2 \
		libwebkitgtk-1.0.so:${PORTSDIR}/www/webkit-gtk2
RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss

USE_GNOME=	gtk20
USES=		desktop-file-utils pkgconfig gettext
INSTALLS_ICONS=	yes

MAKE_ARGS=	PREFIX=${PREFIX}
MAKE_ENV+=	MANDIR=${STAGEDIR}${MANPREFIX}/man

MANDIRS=	${PREFIX}/share/man/man1

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*

.include <bsd.port.mk>
