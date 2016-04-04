# Created by: Max Khon <fjoe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fonulator
PORTVERSION=	2.0.1
PORTREVISION=	2
CATEGORIES=	net net-mgmt
MASTER_SITES=	http://support.red-fone.com/fonulator/

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	FoneBRIDGE configuration utility

BUILD_DEPENDS=	${LOCALBASE}/lib/libargtable2.a:devel/argtable\
		${LOCALBASE}/lib/libfb.a:net/libfb
LIB_DEPENDS=	libnet.so:net/libnet

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-shared

PLIST_FILES=	bin/fonulator \
		man/man1/fonulator.1.gz

post-patch:
	@${REINPLACE_CMD}\
	    -e 's,/usr/lib/libargtable2.a,${LOCALBASE}/lib/libargtable2.a,'\
	    -e 's,/usr/lib/libnet.a,${LOCALBASE}/lib/libnet.a,'\
	    ${WRKSRC}/Makefile.in ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's,/etc/redfone.conf,${LOCALBASE}/etc/redfone.conf,'\
	    ${WRKSRC}/fonulator.c ${WRKSRC}/fonulator.1

.include <bsd.port.mk>
