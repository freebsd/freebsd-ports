# New ports collection makefile for:	gnumeric
# Date created:				08 October 1998
# Whom:					Yukihiro Nakai <Nakai@technologist.com>
#
# $FreeBSD$
#   $MCom: ports/math/gnumeric/Makefile,v 1.14 2005/10/11 22:44:47 marcus Exp $
#

PORTNAME=	gnumeric
PORTVERSION=	1.6.3
PORTREVISION=	1
CATEGORIES=	math gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	The GNOME 2 spreadsheet

LIB_DEPENDS=	goffice-1.2:${PORTSDIR}/devel/goffice \
		psiconv.10:${PORTSDIR}/converters/psiconv

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_X_PREFIX=	yes
USE_PERL5=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix intlhack gnomehack gnomehier libgnomeprintui \
		libgsf_gnome pygtk2 desktopfileutils
USE_PYTHON=	yes
INSTALLS_OMF=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-guile --with-bonobo
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib -liconv ${PTHREAD_LIBS}" \
		python_prog=${PYTHON_VERSION}

GCONF_SCHEMAS=	gnumeric-dialogs.schemas gnumeric-general.schemas \
		gnumeric-plugins.schemas

MAN1=		gnumeric.1 ssconvert.1 ssindex.1

PLIST_SUB=	VERSION=${PORTVERSION}

OPTIONS		GNOMEDB "Enable libgnomedb support" off

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
PLIST_SUB+=	PERL="@comment "
.else
PLIST_SUB+=	PERL=""
.endif

.if defined(WITH_GNOMEDB)
USE_GNOME+=		libgnomedb
CONFIGURE_ARGS+=	--with-gda
PLIST_SUB+=		GNOMEDB=""
.else
CONFIGURE_ARGS+=	--without-gda
PLIST_SUB+=		GNOMEDB="@comment "
.endif

post-patch:
	@${RM} -f ${WRKSRC}/GNOME_Gnumeric.server.in

post-install:
	@-update-desktop-database
.for dir in share/gnome lib
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${PREFIX}/${dir}/gnumeric
.endfor

.include <bsd.port.post.mk>
