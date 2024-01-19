PORTNAME=	squidclamav
PORTVERSION=	7.3
PORTREVISION=	2
CATEGORIES=	www security
MASTER_SITES=	SF

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Clamav c-icap service and redirector for Squid
WWW=		https://squidclamav.darold.net/

LICENSE=	GPLv3+

LIB_DEPENDS=	libicapapi.so:www/c-icap

USES=		cpe libtool shebangfix

CPE_VENDOR=	darold

SHEBANG_FILES=	cgi-bin/clwarn.cgi*
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=	--enable-shared --enable-static \
		--sysconfdir="${PREFIX}/etc/c-icap" \
		--with-c-icap=${LOCALBASE}
INSTALL_TARGET=	install-strip

CFLAGS+=	-DHAVE_STRNSTR

post-patch:
	@${REINPLACE_CMD} -e 's|CFGDIR=.*|CFGDIR="${PREFIX}/etc/c-icap"|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
