# Created by: Yukihiro Nakai <Nakai@technologist.com>
# $FreeBSD$
#   $MCom: ports/trunk/math/gnumeric/Makefile 18444 2013-05-11 12:51:26Z kwm $

PORTNAME=	gnumeric
PORTVERSION=	1.12.11
PORTREVISION=	2
CATEGORIES=	math gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME spreadsheet program

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	rarian-sk-config:${PORTSDIR}/textproc/rarian
LIB_DEPENDS=	libgoffice-0.10.so:${PORTSDIR}/devel/goffice010 \
		libpsiconv.so:${PORTSDIR}/converters/psiconv
RUN_DEPENDS=	rarian-sk-config:${PORTSDIR}/textproc/rarian

USES=		desktop-file-utils gettext gmake libtool pathfix pkgconfig \
		python:2 shebangfix tar:xz
USE_GNOME=	gnomehier gnomeprefix intlhack libgsf pygobject3
INSTALLS_OMF=	yes
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-compile-warnings
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.gnumeric.dialogs.gschema.xml \
		org.gnome.gnumeric.gschema.xml \
		org.gnome.gnumeric.plugin.gschema.xml

SHEBANG_FILES=	plugins/perl-func/perl_func.pl

PLIST_SUB=	VERSION=${PORTVERSION} GOFFICE=0.10 SHORT_VER=1.12

OPTIONS_DEFINE=	PERL GDA
OPTIONS_DEFAULT=PERL
GDA_DESC=	Gnome Database Access plugin
PERL_DESC=	Support Perl as extension language

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPERL}
USES+=			perl5
PLIST_SUB+=		PERL=""
.else
CONFIGURE_ARGS+=	--without-perl
PLIST_SUB+=		PERL="@comment "
.endif

.if ${PORT_OPTIONS:MGDA}
USE_GNOME+=		libgda5-ui
CONFIGURE_ARGS+=	--with-gda
PLIST_SUB+=		GDA=""
.else
CONFIGURE_ARGS+=	--without-gda
PLIST_SUB+=		GDA="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|^GETTEXT_PACKAGE=gnumeric-$${VERSION}|GETTEXT_PACKAGE=gnumeric|g' \
		${WRKSRC}/configure

post-install:
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py -d \
		${PREFIX}/${dir}/gnumeric -f ${STAGEDIR}${PREFIX}/lib/gnumeric/${PORTVERSION}
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py -d \
		${PREFIX}/${dir}/gnumeric -f ${STAGEDIR}${PREFIX}/lib/gnumeric/${PORTVERSION}

.include <bsd.port.mk>
