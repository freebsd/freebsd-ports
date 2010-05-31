# New ports collection makefile for:	shared-mime-info
# Date created:        31 May 2002
# Whom:                olgeni@FreeBSD.org
#
# $FreeBSD$
#   $MCom: ports/misc/shared-mime-info/Makefile,v 1.16 2009/11/28 05:59:02 mezz Exp $
#

PORTNAME=	shared-mime-info
PORTVERSION=	0.71
PORTREVISION=	1
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

MIMEDIRS=	${LOCALBASE}/share/mime \
		${PREFIX}/share/mime
MIMESUBDIRS=	application audio image inode message model multipart \
		packages text video x-epoc x-content

post-patch:
	@${REINPLACE_CMD} -e 's|%%MIMEDIRS%%|${MIMEDIRS}|g' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/update-mime-database.c

post-install:
	@${SED} -e 's|%%PREFIX%%|${PREFIX}| ; \
		s|%%MIMEDIRS%%|${MIMEDIRS}|' \
		< ${FILESDIR}/pkg-install.in > ${PKGINSTALL}

.include <bsd.port.mk>
