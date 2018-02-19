# Created by: Yukihiro Nakai <Nakai@technologist.com>
# $FreeBSD$

PORTNAME=	gnumeric
PORTVERSION=	1.12.28
PORTREVISION=	1
CATEGORIES=	math gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME spreadsheet program

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	rarian-sk-config:textproc/rarian
LIB_DEPENDS=	libgoffice-0.10.so:devel/goffice010 \
		libpsiconv.so:converters/psiconv
RUN_DEPENDS=	rarian-sk-config:textproc/rarian

USES=		cpe desktop-file-utils gettext gmake libtool pathfix pkgconfig \
		python:2.7 shebangfix tar:xz
USE_GNOME=	intlhack libgsf pygobject3
INSTALLS_OMF=	yes
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-compile-warnings \
		--without-paradox \
		--enable-introspection
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

CPE_VENDOR=	gnome

GLIB_SCHEMAS=	org.gnome.gnumeric.dialogs.gschema.xml \
		org.gnome.gnumeric.gschema.xml \
		org.gnome.gnumeric.plugin.gschema.xml

SHEBANG_FILES=	plugins/perl-func/perl_func.pl

PLIST_SUB=	VERSION=${PORTVERSION} \
		GOFFICE=0.10 \
		SHORT_VER=${PORTVERSION:R}

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	PERL GDA
OPTIONS_DEFAULT=PERL
GDA_DESC=	Gnome Database Access plugin
PERL_DESC=	Support Perl as extension language

PERL_USES=	perl5
PERL_CONFIGURE_WITH=	perl

GDA_CONFIGURE_WITH=	gda
GDA_USE=	GNOME=libgda5-ui

post-patch:
	@${REINPLACE_CMD} -e 's|^GETTEXT_PACKAGE=gnumeric-$${VERSION}|GETTEXT_PACKAGE=gnumeric|g' \
		${WRKSRC}/configure

post-install:
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py -d \
		${PREFIX}/${dir}/gnumeric -f ${STAGEDIR}${PREFIX}/lib/gnumeric/${PORTVERSION}
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py -d \
		${PREFIX}/${dir}/gnumeric -f ${STAGEDIR}${PREFIX}/lib/gnumeric/${PORTVERSION}

.include <bsd.port.mk>
