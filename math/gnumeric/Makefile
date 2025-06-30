PORTNAME=	gnumeric
PORTVERSION=	1.12.59
PORTREVISION=	1
CATEGORIES=	math gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME spreadsheet program
WWW=		https://www.gnumeric.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool \
		ginstall:sysutils/coreutils
LIB_DEPENDS=	libgoffice-0.10.so:devel/goffice

USES=		cpe desktop-file-utils gettext gmake gnome libtool \
		localbase pathfix pkgconfig python shebangfix tar:xz
CPE_VENDOR=	gnome
USE_GNOME=	cairo gdkpixbuf glib20 intltool:build introspection gtk30 \
		libgsf libxml2 pango pygobject3
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-gda \
		--without-paradox \
		--without-psiconv \
		--enable-introspection=yes
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.gnumeric.dialogs.gschema.xml \
		org.gnome.gnumeric.gschema.xml \
		org.gnome.gnumeric.plugin.gschema.xml

SHEBANG_FILES=	plugins/perl-func/perl_func.pl

BINARY_ALIAS=	python=${PYTHON_CMD} \
		install=ginstall

PLIST_SUB=	VERSION=${PORTVERSION} \
		GOFFICE=0.10 \
		SHORT_VER=${PORTVERSION:R}

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	PERL
OPTIONS_DEFAULT=PERL

PERL_USES=	perl5
PERL_CONFIGURE_WITH=	perl

post-patch:
	@${REINPLACE_CMD} -e 's|^GETTEXT_PACKAGE=gnumeric-$${VERSION}|GETTEXT_PACKAGE=gnumeric|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
