# Created by: Martin Tournoij <carpetsmoker@xs4all.nl>
# $FreeBSD$

PORTNAME=	pcmanfm
PORTVERSION=	1.1.2
CATEGORIES=	x11-fm
MASTER_SITES=	SF/${PORTNAME}/PCManFM%20%2B%20Libfm%20%28tarball%20release%29/PCManFM/

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	PCMan File Manager

LICENSE=	GPLv2

LIB_DEPENDS=	libstartup-notification-1.so:${PORTSDIR}/x11/startup-notification \
		libfm-gtk.so.4:${PORTSDIR}/x11/libfm

USES=		gmake pkgconfig
USE_GNOME=	gtk20
USE_AUTOTOOLS=	libtool
USE_FAM=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		pcmanfm.1

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext

.include <bsd.port.options.mk>

post-patch:
.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e 's|src po|src|' \
		${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
