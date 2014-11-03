# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xfce4-netload-plugin
PORTVERSION=	1.2.2
CATEGORIES=	sysutils xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=	src/panel-plugins/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Network Load plugin for Xfce4

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
USE_GNOME=	intltool intlhack
USE_XFCE=	configenv libmenu panel
USES=		gmake pkgconfig libtool tar:bzip2
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=	gettext

.include <bsd.port.options.mk>

do-patch:
	@${REINPLACE_CMD} -e 's, || __FreeBSD_kernel__,,' \
		${WRKSRC}/panel-plugin/net.c \
		${WRKSRC}/panel-plugin/net.h \
		${WRKSRC}/panel-plugin/os.h

.if ${PORT_OPTIONS:MNLS}
	${REINPLACE_CMD} -e \
		's|$$(prefix)/$$(DATADIRNAME)/locale|$$(datarootdir)/locale|' \
		${WRKSRC}/po/Makefile.in.in
.else
	${REINPLACE_CMD} -e 's|po ||' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
