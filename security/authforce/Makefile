# Ports collection makefile for:  authforce
# Date created:                   08.05.2002
# Whom:                           ache
#
# $FreeBSD$
#

PORTNAME=	authforce
PORTVERSION=	0.9.9
CATEGORIES=	security www
MASTER_SITES=	http://www.divineinvasion.net/authforce/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	HTTP authentication brute forcer

DEPRECATED=	No more public distfiles
EXPIRATION_DATE=	2012-10-20

LIB_DEPENDS=	curl.6:${PORTSDIR}/ftp/curl

CONFIGURE_ENV=	LIBS="-lintl"
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GETTEXT=	yes

INFO=		authforce
MAN1=		authforce.1
MANCOMPRESSED=	yes

post-patch:
	@${REINPLACE_CMD} -e '/#include <malloc.h>/d' ${WRKSRC}/src/methods.c ${WRKSRC}/src/misc.c
	@${REINPLACE_CMD} -e 's|#include <malloc.h>|#include <stdlib.h>|' ${WRKSRC}/src/extract.c
	@${REINPLACE_CMD} -e '/^pwlistsdir = / s|/data$$||' ${WRKSRC}/data/Makefile.in
	@${REINPLACE_CMD} -e '/<curl\/types.h>/d' ${WRKSRC}/src/http.c

.include <bsd.port.mk>
