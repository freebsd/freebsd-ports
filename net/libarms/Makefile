PORTNAME=	libarms
PORTVERSION=	5.01
PORTREVISION=	2
CATEGORIES=	net devel
MASTER_SITES=	https://dev.smf.jp/dl/ \
		http://dev.smf.jp/dl/

MAINTAINER=	shigeru@iij.ad.jp
COMMENT=	SMFv2/ARMS client library for C
WWW=		https://dev.smf.jp/libarms/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Obsolete version and not updated in a decade
EXPIRATION_DATE=2025-07-31

LIB_DEPENDS=	libexpat.so:textproc/expat2

USES=		gmake libtool localbase ssl
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

post-configure:
	@${REINPLACE_CMD} 's|$${datarootdir}/doc/$${PACKAGE_TARNAME}|${DOCSDIR}|' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
