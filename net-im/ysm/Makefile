# New ports collection makefile for:	ysm
# Date created:				May 28, 2002
# Whom:					vampiro
#
# $FreeBSD$
#

PORTNAME=	ysm
PORTVERSION=	7.2.9.9.1
PORTREVISION=	1
CATEGORIES=	net-im
MASTER_SITES=	SF/${PORTNAME}v7/${PORTNAME}v7/${PORTNAME}v7%202.9.9.1
DISTNAME=	${PORTNAME}v${PORTVERSION:S/./_/g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command line ICQ client with ICQ2000 and recoding support

USE_ICONV=	yes
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
