# Created by: Milan Obuch
# $FreeBSD$

PORTNAME=	clamcour
PORTVERSION=	0.3.8
PORTREVISION=	9
CATEGORIES=	security mail
MASTER_SITES=	http://www.becrux.com/pages/projects/clamcour/

MAINTAINER=	bsd@dino.sk
COMMENT=	ClamAV courier filter

BUILD_DEPENDS=	courier-config:mail/courier
LIB_DEPENDS=	libclamav.so:security/clamav

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--with-clamav-config=${LOCALBASE}/bin \
		--with-courier-config=${LOCALBASE}/bin
CPPFLAGS+=	-I${LOCALBASE}/include
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-lpthread -L${LOCALBASE}/lib

PLIST_DIRS=	etc/courier/clamcour
PLIST_FILES=	libexec/filters/clamcour man/man1/clamcour.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's/^CXXFLAGS *=/CXXFLAGS?=/g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/cl_limits/d; s/cl_node/cl_engine/' \
		${WRKSRC}/src/clam.h

.include <bsd.port.mk>
