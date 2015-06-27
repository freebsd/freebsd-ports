# Created by: Sergei Kolobov <sergei@kolobov.com>
# $FreeBSD$

PORTNAME=	libtasn1
PORTVERSION=	4.5
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	libtasn1

MAINTAINER=	novel@FreeBSD.org
COMMENT=	ASN.1 structure parser library

USE_LDCONFIG=	yes
USES=		cpe pkgconfig pathfix gmake libtool
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
CPE_VENDOR=	gnu

OPTIONS_DEFINE=	DOCS

DOCS=		AUTHORS NEWS README THANKS doc/TODO \
		doc/libtasn1.html doc/libtasn1.pdf doc/libtasn1.ps
INFO=		libtasn1

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
