# New ports collection makefile for:	ysm
# Date created:				May 28, 2002
# Whom:					vampiro
#
# $FreeBSD$
#

PORTNAME=	ysm
PORTVERSION=	7.2.9.4
CATEGORIES=	net
MASTER_SITES=	ftp://rusunix.org/pub/FreeBSD/distfiles/ \
		http://aquatique.rusunix.org/
DISTNAME=	${PORTNAME}v${PORTVERSION:S/./_/g}

MAINTAINER=	aquatique-ports@rambler.ru
COMMENT=	Command line ICQ client with ICQ2000 and recoding support

USE_ICONV=	yes
USE_REINPLACE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		CFLAGS+="-I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib -liconv"

MAN1=		ysm.1
PLIST_FILES=	bin/ysm

post-patch:
	@${REINPLACE_CMD} -e \
		's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

.include <bsd.port.mk>
