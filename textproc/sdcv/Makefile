# Created by: chinsan <chinsan.tw@gmail.com>
# $FreeBSD$

PORTNAME=	sdcv
PORTVERSION=	0.4.2
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Text-based utility for work with dictionaries in StarDict's format

LICENSE=	GPLv2 # (or later)

USES=		gettext pkgconfig readline tar:bzip2
USE_GNOME=	glib20
USE_AUTOTOOLS=	libtoolize aclocal automake autoconf
ACLOCAL_ARGS=	--automake-acdir=${ACLOCAL_DIR} -I m4
AUTOMAKE_ARGS=	--add-missing --copy

SUB_FILES=	pkg-message

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
.for i in doc/sdcv.1 src/sdcv.cpp
	@${REINPLACE_CMD} -e \
		's|/usr/share|${PREFIX}/share|' ${WRKSRC}/${i}
.endfor
	@${REINPLACE_CMD} -e \
		's|@mandir@/uk|@mandir@|' ${WRKSRC}/doc/uk/Makefile.am
	@${REINPLACE_CMD} -e \
		's|getopt1.c getopt.h||' ${WRKSRC}/src/Makefile.am

pre-configure:
	@${RM} -f ${WRKSRC}/m4/gettext.m4
	@${RM} -f ${WRKSRC}/src/getopt.h

.include <bsd.port.mk>
