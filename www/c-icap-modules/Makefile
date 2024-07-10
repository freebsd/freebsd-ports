PORTNAME=	c-icap
PORTVERSION=	0.5.7
CATEGORIES=	www security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}${PKGNAMESUFFIX}/0.5.x/
PKGNAMESUFFIX=	-modules
DISTNAME=	c_icap_modules-${PORTVERSION}

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Modules for c-icap: virus_scan and srv_url_check
WWW=		https://c-icap.sourceforge.net/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libclamav.so:security/clamav \
		libicapapi.so:www/c-icap

USES=				libtool autoreconf
GNU_CONFIGURE=			yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=			--enable-static \
				--with-c-icap=${LOCALBASE} \
				--with-clamav=${LOCALBASE}
INSTALL_TARGET=			install-strip

CFLAGS+=	-DHAVE_STRNSTR

DATADIR=	${PREFIX}/share/c_icap

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/c-icap

.include <bsd.port.mk>
