# New ports collection makefile for:	bookcase
# Date created:				11 May 2003
# Whom:					Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	bookcase
PORTVERSION=	0.8.3
CATEGORIES=	misc kde
MASTER_SITES=	http://www.periapsis.org/bookcase/download/

MAINTAINER=	markus@FreeBSD.org
COMMENT=	Personal book collection manager for KDE

USE_KDELIBS_VER=3
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g' ${WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's|strings.h|bc_strings.h|g' \
		${WRKSRC}/src/Makefile.in \
		${WRKSRC}/src/filehandler.cpp \
		${WRKSRC}/src/translators/bibtexmlimporter.cpp \
		${WRKSRC}/src/translators/bookcaseimporter.cpp
	@${MV} ${WRKSRC}/src/strings.h ${WRKSRC}/src/bc_strings.h
	@${TOUCH} ${WRKSRC}/config.h.in

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
CFLAGS+=	-D__LIBSTDCPP_PARTIAL_SUPPORT__
.endif

.include "${PORTSDIR}/x11/kde3/Makefile.kde"
.include <bsd.port.post.mk>
