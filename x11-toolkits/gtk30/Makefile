# New ports collection makefile for:   gtk12
# Version required:		1.2.6
# Date Created:			28 Sep 1997
# Whom:				Vanilla I. Shu <vanilla@MinJe.com.TW>
#
# $FreeBSD$
#

DISTNAME=	gtk+-1.2.6
PKGNAME=	gtk-1.2.6
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://ftp.gimp.org/pub/gtk/v1.2/ \
		ftp://ftp.cs.umn.edu/pub/gimp/gtk/v1.2/ \
		http://www.ameth.org/gimp/gtk/v1.2/

MAINTAINER=	vanilla@FreeBSD.org

LIB_DEPENDS=	glib12.3:${PORTSDIR}/devel/glib12 \
		intl.1:${PORTSDIR}/devel/gettext

GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config

USE_X_PREFIX=	yes
USE_PERL5=	yes
USE_LIBTOOL=	yes
LIBTOOLFLAGS=	--disable-ltlibs --release-suffix
CONFIGURE_ARGS=	--includedir=${PREFIX}/include/gtk12
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		X_CFLAGS="-I${LOCALBASE}/include" \
		GLIB_CONFIG="${GLIB_CONFIG}" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=		gtk12-config.1

pre-build:
	${RM} -rf ${WRKSRC}/docs/gtk.info*

.include <bsd.port.mk>
