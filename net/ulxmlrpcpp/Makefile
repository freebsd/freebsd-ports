PORTNAME=	ulxmlrpcpp
PORTVERSION=	1.7.5
PORTREVISION=	3
CATEGORIES=	net devel
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ultra lightweight xml-rpc library written in C++
WWW=		https://ulxmlrpcpp.sourceforge.net/

LIB_DEPENDS=	libexpat.so:textproc/expat2

USES=		compiler:c++11-lang iconv libtool localbase:ldflags \
		pathfix ssl tar:bzip2
USE_CXXSTD=	c++14
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PTHREAD_LIBS="-lpthread"

INSTALL_TARGET=	install-strip

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e \
		'/^SUBDIRS/s| docs | |g' ${WRKSRC}/ulxmlrpcpp/Makefile.in

.include <bsd.port.mk>
