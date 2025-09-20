PORTNAME=	liveMedia
DISTVERSION=	2025.09.17
PORTEPOCH=	2
CATEGORIES=	net devel
MASTER_SITES=	https://download.videolan.org/contrib/live555/
DISTNAME=	live.${DISTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	LIVE.COM Streaming Media
WWW=		http://www.live555.com/liveMedia/

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

USES=		compiler:c++11-lang gmake ssl
USE_CXXSTD=	c++11
USE_LDCONFIG=	yes

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	genMakefiles
CONFIGURE_ARGS=		linux-with-shared-libraries

WRKSRC=		${WRKDIR}/live

post-patch:
	@${REINPLACE_CMD} \
		-e '/^PREFIX/s|=|?=|' \
			${WRKSRC}/*/Makefile.head
	@${REINPLACE_CMD} \
		-e 's|install -m 644 include|$${BSD_INSTALL_DATA} include|' \
		-e 's|install -m 644|$${BSD_INSTALL_LIB}|' \
		-e 's|install -m 755|$${BSD_INSTALL_PROGRAM}|' \
			${WRKSRC}/*/Makefile.tail

.include <bsd.port.mk>
