# New ports collection makefile for:	gnumeric
# Date created:				08 October 1998
# Whom:					Yukihiro Nakai <Nakai@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	gnumeric
PORTVERSION=	1.4.3
PORTREVISION=	1
CATEGORIES=	math gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	The GNOME 2 spreadsheet

LIB_DEPENDS=	psiconv.10:${PORTSDIR}/converters/psiconv

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_PERL5=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix intlhack gnomehack gnomehier libgnomeprintui \
		libgnomedb libgsf_gnome pygtk2 desktopfileutils
USE_PYTHON=	yes
INSTALLS_OMF=	yes
USE_REINPLACE=	yes
USE_LIBTOOL_VER=15
CONFIGURE_ARGS=	--without-guile --with-bonobo --with-gnome-db
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib -liconv ${PTHREAD_LIBS}" \
		DEFS="-I${X11BASE}/include/gal-2.0" \
		python_prog=${PYTHON_VERSION}

GCONF_SCHEMAS=	gnumeric-dialogs.schemas gnumeric-general.schemas \
		gnumeric-plugins.schemas

MAN1=		gnumeric.1 ssconvert.1

PLIST_SUB=	VERSION=${PORTVERSION}

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
# The Perl plug-ins don't build with Perl < 5.6.1
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-plugins_Makefile.in
.endif

post-patch:
	@cd ${WRKSRC} && ${REINPLACE_CMD} -e 's,malloc.h,stdlib.h,' \
		src/tools/solver/lp_solve/commonlib.h \
		src/tools/solver/lp_solve/fortify.c \
		src/tools/solver/lp_solve/lp_Hash.c \
		src/tools/solver/lp_solve/lp_etaPFI.c \
		src/tools/solver/lp_solve/lp_lib.h \
		src/tools/solver/lp_solve/lp_rlp.c \
		src/tools/solver/lp_solve/lp_rlpt.c
	@${FIND} ${WRKSRC}/plugins -name "plugin.xml.in" | ${XARGS} \
		${REINPLACE_CMD} -e 's|\.la|.so|g'
	@${FIND} ${WRKSRC}/src/cut-n-paste-code/goffice/graph/plugins -name \
		"plugin.xml.in" | ${XARGS} ${REINPLACE_CMD} -e 's|\.la|.so|g'
	@${RM} -f ${WRKSRC}/GNOME_Gnumeric.server.in

post-install:
.for dir in share/gnome lib
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${PREFIX}/${dir}/gnumeric
.endfor
	@-update-desktop-database

.include <bsd.port.post.mk>
