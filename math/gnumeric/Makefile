# New ports collection makefile for:	gnumeric
# Date created:				08 October 1998
# Whom:					Yukihiro Nakai <Nakai@technologist.com>
#
# $FreeBSD$
#   $MCom: ports/math/gnumeric/Makefile,v 1.46 2008/10/20 21:37:28 kwm Exp $
#

PORTNAME=	gnumeric
PORTVERSION=	1.10.4
CATEGORIES=	math gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	The GNOME 2 spreadsheet

LIB_DEPENDS=	goffice-0.8.8:${PORTSDIR}/devel/goffice \
		psiconv.10:${PORTSDIR}/converters/psiconv

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix intlhack gnomehack gnomehier \
		libgsf_gnome pygtk2 desktopfileutils libgnomeui
USE_PYTHON=	yes
INSTALLS_OMF=	yes
USE_LDCONFIG=	yes
WANT_PERL=	yes
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gnome
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib -liconv ${PTHREAD_LIBS}" \
		python_prog=${PYTHON_VERSION}

GCONF_SCHEMAS=	gnumeric-dialogs.schemas gnumeric-general.schemas \
		gnumeric-plugins.schemas

MAN1=		gnumeric.1 ssconvert.1 ssindex.1 ssgrep.1

PLIST_SUB=	VERSION=${PORTVERSION} GOFFICE=0.8.4

OPTIONS=	PERL "Enable Perl as extension language" on
#GNOMEDB "Enable libgnomedb support" off

.include <bsd.port.pre.mk>

.if defined(WITH_PERL)
USE_PERL5=		yes
PLIST_SUB+=		PERL=""
.else
CONFIGURE_ARGS+=	--without-perl
PLIST_SUB+=		PERL="@comment "
.endif

#.if defined(WITH_GNOMEDB)
#USE_GNOME+=		libgnomedb
#CONFIGURE_ARGS+=	--with-gda
#PLIST_SUB+=		GNOMEDB=""
#.else
CONFIGURE_ARGS+=	--without-gda
PLIST_SUB+=		GNOMEDB="@comment "
#.endif

post-patch:
	@${RM} -f ${WRKSRC}/GNOME_Gnumeric.server.in
	@${REINPLACE_CMD} -e 's|gda-3.0 >= 3.1.1|gda-3.0 >= 3.0.1|g' \
		-e 's|gnomedb-3.0 >= 3.0.1|gnomedb-3.0 >= 3.0.0|g' \
		${WRKSRC}/configure

post-install:
	${INSTALL_DATA} ${WRKSRC}/gnumeric.desktop ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/gnumeric.mime ${PREFIX}/share/mime-info
	@-update-desktop-database
.for dir in share lib
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${PREFIX}/${dir}/gnumeric
.endfor

.include <bsd.port.post.mk>
