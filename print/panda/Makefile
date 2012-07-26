# New ports collection makefile for:	Panda
# Date created:		28 March 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	panda
PORTVERSION=	0.5.4
PORTREVISION=	5
CATEGORIES=	print
MASTER_SITES=	SF \
		SAVANNAH \
		http://www.stillhq.com/panda/source/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A PDF generation library

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	dual

LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff

USE_BZIP2=	yes
USE_GNOME=	gnomehack
USE_BDB=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--enable-berkeley-db
USE_LDCONFIG=	yes
USE_PKGCONFIG=	yes
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${BDB_INCLUDE_DIR} -I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${BDB_LIB_DIR} -L${LOCALBASE}/lib ${PTHREAD_LIBS}

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
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
.for f in IMAGES examples/*.c examples/c++/*.cpp examples/images/*.*
	${INSTALL_DATA} ${WRKSRC}/${f} ${EXAMPLESDIR}
.endfor
.endif

.include "Makefile.man"
.include <bsd.port.post.mk>
