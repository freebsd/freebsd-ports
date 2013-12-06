# Created by: vampiro
# $FreeBSD$

PORTNAME=	ysm
PORTVERSION=	7.2.9.9.1
PORTREVISION=	1
CATEGORIES=	net-im
MASTER_SITES=	SF/${PORTNAME}v7/${PORTNAME}v7/${PORTNAME}v7%202.9.9.1
DISTNAME=	${PORTNAME}v${PORTVERSION:S/./_/g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command line ICQ client with ICQ2000 and recoding support

BROKEN=		Fails to install

USE_CSTD=	c89

USES=		iconv gmake
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}

MAN1=		ysm.1
PLIST_FILES=	bin/ysm

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e \
		's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

.include <bsd.port.mk>
