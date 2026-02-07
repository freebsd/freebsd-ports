PORTNAME=	sipsak
DISTVERSION=	0.9.8.1
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	https://github.com/nils-ohlmeier/sipsak/releases/download/${DISTVERSION}/

MAINTAINER=	jesusr@FreeBSD.org
COMMENT=	Small command line tool for SIP testing
WWW=		https://github.com/nils-ohlmeier/sipsak

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		pkgconfig
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

PLIST_FILES=	bin/sipsak \
		share/man/man1/sipsak.1.gz

OPTIONS_DEFINE=		CARES GNUTLS
OPTIONS_DEFAULT=	CARES GNUTLS
CARES_LIB_DEPENDS=	libcares.so:dns/c-ares
GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
.include <bsd.port.mk>
