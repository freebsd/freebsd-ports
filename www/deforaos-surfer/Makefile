# Created by: Olivier Cochard-Labbe <olivier@FreeBSD.org>
# $FreeBSD$

PORTNAME=	surfer
PORTVERSION=	0.2.9
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.defora.org/os/download/download/4411/
PKGNAMEPREFIX=	deforaos-
DISTNAME=	Surfer-${PORTVERSION}

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	DeforaOS desktop web browser

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libSystem.so:devel/deforaos-libsystem \
		libDesktop.so:x11/deforaos-libdesktop \
		libgnet-2.0.so:net/gnet2 \
		libwebkitgtk-1.0.so:www/webkit-gtk2
RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

DEPRECATED=	Uses webkit-gtk2 which has security issues
EXPIRATION_DATE=2019-03-24

USE_GNOME=	gtk20
USES=		desktop-file-utils pkgconfig
INSTALLS_ICONS=	yes

MAKE_ARGS=	PREFIX=${PREFIX}
MAKE_ENV+=	MANDIR=${STAGEDIR}${MANPREFIX}/man

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes
NLS_USES=	gettext
DOCS_BUILD_DEPENDS=	xsltproc:textproc/libxslt \
	${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:textproc/docbook-xsl

post-patch-DOCS-off:
	${REINPLACE_CMD} 's|= data doc|= data|' \
		${WRKSRC}/Makefile

post-patch-NLS-off:
	${REINPLACE_CMD} 's|po src tools|src tools|' \
		${WRKSRC}/Makefile

post-patch:
	${REINPLACE_CMD} 's|-Wl,-pie||g' \
		${WRKSRC}/tools/Makefile \
		${WRKSRC}/src/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*

.include <bsd.port.mk>
