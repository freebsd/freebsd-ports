# Created by: Anders F Bjorklund <afb@users.sourceforge.net>
# $FreeBSD$
#  $MCom: ports/ports-mgmt/gnome-packagekit/Makefile,v 1.25 2011/06/14 20:18:46 mezz Exp $

PORTNAME=	gnome-packagekit
PORTVERSION=	2.32.0
PORTREVISION=	3
CATEGORIES=	ports-mgmt sysutils gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	PackageKit client programs for the GNOME desktop

BUILD_DEPENDS=	${LOCALBASE}/bin/docbook2man:${PORTSDIR}/textproc/docbook-utils
LIB_DEPENDS=	dbus-glib-1:${PORTSDIR}/devel/dbus-glib \
		packagekit-glib2:${PORTSDIR}/ports-mgmt/packagekit \
		notify:${PORTSDIR}/devel/libnotify \
		unique-1.0:${PORTSDIR}/x11-toolkits/unique \
		upower-glib:${PORTSDIR}/sysutils/upower \
		canberra-gtk:${PORTSDIR}/audio/libcanberra

USE_BZIP2=	yes
USE_GNOME=	gnomeprefix intlhack gconf2 gnomemenus gnomedocutils
USES=		desktop-file-utils gettext iconv pathfix gmake pkgconfig
USE_PYTHON_BUILD=2
GCONF_SCHEMAS=	gnome-packagekit.schemas
INSTALLS_ICONS=	yes
INSTALLS_OMF=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=	gpk-application.1 gpk-backend-status.1 gpk-install-local-file.1 \
	gpk-install-mime-type.1 gpk-install-package-name.1 \
	gpk-install-provide-file.1 gpk-prefs.1 gpk-repo.1 gpk-update-icon.1 \
	gpk-update-viewer.1

NO_STAGE=	yes
pre-configure:
	@${REINPLACE_CMD} -E -e 's/.*CPPFLAGS.*-Werror/#$$&/' \
		-e 's|-Wmissing-include-dirs||g' ${WRKSRC}/configure

.include <bsd.port.mk>
