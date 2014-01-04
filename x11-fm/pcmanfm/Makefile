# Created by: Martin Tournoij <carpetsmoker@xs4all.nl>
# $FreeBSD$

PORTNAME=	pcmanfm
PORTVERSION=	1.1.2
PORTREVISION=	1
CATEGORIES=	x11-fm
MASTER_SITES=	SF/${PORTNAME}/PCManFM%20%2B%20Libfm%20%28tarball%20release%29/PCManFM/

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	PCMan File Manager

LICENSE=	GPLv2

LIB_DEPENDS=	libstartup-notification-1.so:${PORTSDIR}/x11/startup-notification \
		libfm-gtk.so.4:${PORTSDIR}/x11/libfm

USES=		fam gmake pkgconfig
USE_GNOME=	gtk20
USE_AUTOTOOLS=	libtool
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e '/pcmanfm.conf/ d' ${WRKSRC}/data/Makefile.in
.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e 's|src po|src|' \
		${WRKSRC}/Makefile.in
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/xdg/pcmanfm/default/
	${INSTALL_DATA} ${WRKSRC}/data/pcmanfm.conf \
		${STAGEDIR}${PREFIX}/etc/xdg/pcmanfm/default/pcmanfm.conf.sample

.include <bsd.port.mk>
