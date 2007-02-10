# New ports collection makefile for:	shared-mime-info
# Date created:        31 May 2002
# Whom:                olgeni@FreeBSD.org
#
# $FreeBSD$

PORTNAME=	shared-mime-info
PORTVERSION=	0.20
CATEGORIES=	misc gnome
MASTER_SITES=	http://people.freedesktop.org/~hadess/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A MIME type database from the FreeDesktop project

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	glib20 libxml2 intltool gnomehack intlhack
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		update-mime-database.1

PKGINSTALL=	${WRKDIR}/pkg-install

MIMEDIRS=	${X11BASE}/share/gnome/mime \
		${LOCALBASE}/share/gnome/mime \
		${X11BASE}/share/mime \
		${LOCALBASE}/share/mime \
		${PREFIX}/share/mime \
		/usr/share/mime
MIMESUBDIRS=	application audio image inode message model multipart \
		packages text video

post-patch:
	@${REINPLACE_CMD} -e 's|%%MIMEDIRS%%|${MIMEDIRS}|g' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g ; \
		s|%%X11BASE%%|${X11BASE}|g' \
		${WRKSRC}/update-mime-database.c

pre-su-install:
.for subdir in ${MIMESUBDIRS}
	${MKDIR} ${X11BASE}/share/mime/${subdir}
.endfor

post-install:
	@${SED} -e 's|%%PREFIX%%|${PREFIX}| ; \
		s|%%MIMEDIRS%%|${MIMEDIRS}|' \
		< ${FILESDIR}/pkg-install.in > ${PKGINSTALL}

.include <bsd.port.mk>
