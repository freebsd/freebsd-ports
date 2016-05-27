# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	squidclamav
PORTVERSION=	6.14
CATEGORIES=	www security
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Clamav c-icap service and redirector for Squid

LICENSE=	GPLv3+

LIB_DEPENDS=	libicapapi.so:www/c-icap

USES=		cpe libtool shebangfix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared --enable-static \
		--sysconfdir="${PREFIX}/etc/c-icap" \
		--with-c-icap=${LOCALBASE}
SHEBANG_FILES=	cgi-bin/clwarn.cgi*
CPE_VENDOR=	darold
INSTALL_TARGET=	install-strip

CFLAGS+=	-DHAVE_STRNSTR

post-patch:
	@${REINPLACE_CMD} -e 's|CFGDIR=.*|CFGDIR="${PREFIX}/etc/c-icap"|g' \
		${WRKSRC}/configure.in ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/etc/squidclamav.conf|${PREFIX}/etc/c\\-icap/squidclamav.conf|g' \
		${WRKSRC}/doc/squidclamav.1 ${WRKSRC}/src/squidclamav.h

.include <bsd.port.mk>
