# Created by: Yukihiro Nakai <Nakai@technologist.com>
# $FreeBSD$
#   $MCom: ports/trunk/math/gnumeric/Makefile 18444 2013-05-11 12:51:26Z kwm $

PORTNAME=	gnumeric
PORTVERSION=	1.12.9
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

USE_XZ=		yes
USES=		desktop-file-utils gettext gmake pathfix pkgconfig \
		shared-mime-info shebangfix
USE_GNOME=	gnomehier gnomeprefix intlhack libgsf pygobject3
USE_PYTHON=	2
INSTALLS_OMF=	yes
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

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

.if defined(WITH_GDA)
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
	${INSTALL_DATA} ${WRKSRC}/gnumeric.desktop ${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/gnumeric.mime ${STAGEDIR}${PREFIX}/share/mime-info
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py -d \
		${STAGEDIR}${PREFIX}/${dir}/gnumeric -f ${STAGEDIR}${PREFIX}/lib/gnumeric/${PORTVERSION}
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py -d \
		${STAGEDIR}${PREFIX}/${dir}/gnumeric -f ${STAGEDIR}${PREFIX}/lib/gnumeric/${PORTVERSION}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libspreadsheet-${PORTVERSION}.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/gnumeric/${PORTVERSION}/plugins/*/*.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/goffice/0.10/plugins/gnumeric/gnumeric.so

.include <bsd.port.mk>

