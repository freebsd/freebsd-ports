# Created by: Olivier Cochard-Labbe <olivier@cochard.me>
# $FreeBSD$

PORTNAME=	mailer
PORTVERSION=	0.1.5
CATEGORIES=	mail
MASTER_SITES=	http://www.defora.org/os/download/download/3704/
DISTNAME=	Mailer-${PORTVERSION}
PKGNAMEPREFIX=	deforaos-

MAINTAINER=	olivier@cochard.me
COMMENT=	DeforaOS desktop mail client

LICENSE=	GPLv3

BUILD_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt \
		${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:${PORTSDIR}/textproc/docbook-xsl
LIB_DEPENDS=	System:${PORTSDIR}/devel/deforaos-libsystem \
		Desktop:${PORTSDIR}/x11/deforaos-libdesktop

USE_GNOME=	gtk20 desktopfileutils
USE_PKGCONFIG=	build
USE_GETTEXT=	yes
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
USE_OPENSSL=	yes

MAKE_ENV+=	MANDIR=${MANPREFIX}/man

MAN1=		compose.1 \
		mailer.1

post-patch:
	${REINPLACE_CMD} -e 's|/lib/|/libdata/|g' \
		${WRKSRC}/data/pkgconfig.sh

.include <bsd.port.mk>
