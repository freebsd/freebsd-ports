# New ports collection makefile for:	Panda
# Date created:		28 March 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	panda
PORTVERSION=	0.5.4
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		${MASTER_SITE_SAVANNAH} \
		http://www.stillhq.com/panda/source/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A PDF generation library

LIB_DEPENDS=	db41.1:${PORTSDIR}/databases/db41 \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff

USE_BZIP2=	yes
USE_GNOME=	gnomehack gnometarget lthack pkgconfig
USE_GMAKE=	yes
USE_LIBTOOL_VER=	13
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--enable-berkeley-db
INSTALLS_SHLIB=	yes

CPPFLAGS=	-I${LOCALBASE}/include/db41 -I${LOCALBASE}/include \
		${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.pre.mk>

post-extract:
.for file in config.sub config.guess
	@${RM} ${WRKSRC}/config/${file} && ${TOUCH} ${WRKSRC}/config/${file}
.endfor

post-patch:
	@${REINPLACE_CMD} -e 's| -lpanda| $$(top_srcdir)/libpanda.la|g' \
		${WRKSRC}/examples/Makefile.in

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/panda_*.3 ${MANPREFIX}/man/man3
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in AUTHORS CONTRIBUTORS ChangeLog DEV-HINTS README TODO UNDERWAY
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
	@${MKDIR} ${EXAMPLESDIR}
.for f in IMAGES examples/*.c examples/c++/*.cpp examples/images/*.*
	${INSTALL_DATA} ${WRKSRC}/${f} ${EXAMPLESDIR}
.endfor
.endif

.include "Makefile.man"
.include <bsd.port.post.mk>
