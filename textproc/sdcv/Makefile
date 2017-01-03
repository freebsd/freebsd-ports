# Created by: chinsan <chinsan.tw@gmail.com>
# $FreeBSD$

PORTNAME=	sdcv
PORTVERSION=	0.4.2
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Text-based utility for work with dictionaries in StarDict's format

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
USES=		autoreconf gettext pkgconfig readline tar:bzip2
USE_GNOME=	glib20

SUB_FILES=	pkg-message

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

post-patch:
.for i in doc/sdcv.1 src/sdcv.cpp
	@${REINPLACE_CMD} -e \
		's|/usr/share|${PREFIX}/share|' ${WRKSRC}/${i}
.endfor
	@${REINPLACE_CMD} -e \
		's|@mandir@/uk|@mandir@|' ${WRKSRC}/doc/uk/Makefile.am
	@${REINPLACE_CMD} -e \
		's|getopt1.c getopt.h||' ${WRKSRC}/src/Makefile.am
	@${RM} ${WRKSRC}/src/getopt.h
	@${REINPLACE_CMD} '/AM_GNU_GETTEXT_VERSION/s/0\.14\.1/0.19.1/' \
		${WRKSRC}/configure.ac

.include <bsd.port.mk>
