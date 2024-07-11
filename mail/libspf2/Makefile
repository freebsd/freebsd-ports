PORTNAME=	libspf2
PORTVERSION=	1.2.11
PORTREVISION=	2
CATEGORIES=	mail

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Sender Policy Framework 2 C Implementation
WWW=		https://www.libspf2.org/ \
		https://github.com/shevek/libspf2

LICENSE=	BSD2CLAUSE LGPL21 LGPL3
LICENSE_COMB=	dual

USES=		autoreconf cpe libtool

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	shevek
GH_TAGNAME=	d14abff

post-patch:
	@${REINPLACE_CMD} -e '/__VA_ARGS__/ s|format, ||g' ${WRKSRC}/src/include/spf_log.h

.include <bsd.port.mk>
