# New ports collection makefile for:	Panda
# Date created:		28 March 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	panda
PORTVERSION=	0.5.3
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	http://www.stillhq.com/panda/source/
DISTNAME=	${PORTNAME}_${PORTVERSION:S/./_/g}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GPL PDF generation library

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

post-extract:
.for file in config.sub config.guess
	@${RM} ${WRKSRC}/config/${file} && ${TOUCH} ${WRKSRC}/config/${file}
.endfor

post-patch:
	@${REINPLACE_CMD} -e 's| -lpanda| \$$(top_srcdir)/libpanda.la|g' \
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
