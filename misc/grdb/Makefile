# New ports collection makefile for:   grdb
# Date created:        13 June 2000
# Whom:                Stijn Hoop <stijn@win.tue.nl>
#
# $FreeBSD$
#

PORTNAME=	grdb
PORTVERSION= 	0.2.1
CATEGORIES=	misc gnome
MASTER_SITES=   http://bucket.pp.ualr.edu/~bit/download/

MAINTAINER=	stijn@win.tue.nl

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt \
		gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
		${GNOME_DEPENDS}

.if !defined(WITHOUT_GNOME)
GNOME_DEPENDS=	gnome.4:${PORTSDIR}/x11/gnomelibs \
		capplet.4:${PORTSDIR}/sysutils/gnomecontrolcenter
.endif

USE_X_PREFIX=	yes

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
GTK_CONFIG?=	${PREFIX}/bin/gtk12-config
CONFIGURE_ENV=	GTK_CONFIG="${GTK_CONFIG}" \
		CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.if defined(WITHOUT_GNOME)
CONFIGURE_ARGS=	--disable-gnome
.endif

.if !defined(WITHOUT_GNOME)
pre-extract:
	@${ECHO} "===>  NOTE: You can remove support for the Gnome control panel"
	@${ECHO} "===>        by defining WITHOUT_GNOME"
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/grdb
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/grdb
	@${ECHO} "share/doc/grdb/README" >> ${TMPPLIST}
	@${ECHO} "@dirrm share/doc/grdb" >> ${TMPPLIST}
.endif
.if !defined(WITHOUT_GNOME)
	@${ECHO} "bin/grdb-capplet" >> ${TMPPLIST}
	@${ECHO} "share/gnome/control-center/Desktop/grdb-capplet.desktop" >> ${TMPPLIST}
	@${ECHO} "share/gnome/apps/Settings/Desktop/grdb-capplet.desktop" >> ${TMPPLIST}
	@${ECHO} "share/gnome/pixmaps/grdb-capplet.png" >> ${TMPPLIST}
.endif

.include <bsd.port.mk>
