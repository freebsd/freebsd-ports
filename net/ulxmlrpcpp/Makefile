# Created by: ijliao
# $FreeBSD$

PORTNAME=	ulxmlrpcpp
PORTVERSION=	1.7.5
PORTREVISION=	3
CATEGORIES=	net devel
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ultra lightweight xml-rpc library written in C++

LIB_DEPENDS=	libexpat.so:textproc/expat2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		compiler:c++11-lang tar:bzip2 pathfix iconv libtool ssl
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PTHREAD_LIBS="-lpthread"
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e \
		'/^SUBDIRS/s| docs | |g' ${WRKSRC}/ulxmlrpcpp/Makefile.in

.include <bsd.port.mk>
