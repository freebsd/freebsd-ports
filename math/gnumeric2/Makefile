# New ports collection makefile for:	gnumeric2
# Date created:				26 August 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnumeric2
PORTVERSION=	1.2.10
CATEGORIES=	math gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME:S/2$//}/1.2
DISTNAME=	${PORTNAME:S/2$//}-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	The GNOME 2 spreadsheet

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-2.0/gtk/_gtk.so:${PORTSDIR}/x11-toolkits/py-gtk2
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-2.0/gtk/_gtk.so:${PORTSDIR}/x11-toolkits/py-gtk2

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_PERL5=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gnomehier libgnomeprintui libgnomedb \
		libgsf
USE_PYTHON=	yes
USE_REINPLACE=	yes
USE_LIBTOOL_VER=13
CONFIGURE_ARGS=	--without-guile --with-bonobo --with-gnome-db
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib -liconv ${PTHREAD_LIBS}" \
		DEFS="-I${X11BASE}/include/gal-2.0" \
		python_prog=${PYTHON_VERSION}

PLIST_SUB=	VERSION=${PORTVERSION}-bonobo

MAN1=		gnumeric.1 ssconvert.1

post-patch:
	@${FIND} ${WRKSRC}/plugins -name "plugin.xml.in" | ${XARGS} \
		${REINPLACE_CMD} -e 's|\.la|.so|g'
	@${FIND} ${WRKSRC}/src/cut-n-paste-code/goffice/graph/plugins -name \
		"plugin.xml.in" | ${XARGS} ${REINPLACE_CMD} -e 's|\.la|.so|g'
	@${RM} -f ${WRKSRC}/GNOME_Gnumeric.server.in
	@${FIND} ${WRKSRC} -name "intltool-merge.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|mkdir $$lang or|mkdir $$lang, 0777 or| ; \
		 s|^push @INC, "/.*|push @INC, "${LOCALBASE}/share/intltool";|'

post-install:
.for dir in share/gnome lib
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${PREFIX}/${dir}/gnumeric
.endfor

.include <bsd.port.mk>
