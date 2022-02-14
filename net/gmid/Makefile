PORTNAME=	gmid
DISTVERSION=	1.8.1
CATEGORIES=	net
MASTER_SITES=	https://github.com/omar-polo/gmid/releases/download/${DISTVERSION}/

MAINTAINER=	freebsd@omarpolo.com
COMMENT=	Simple and secure Gemini server

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libevent.so:devel/libevent \
		libtls.so:security/libressl

USES=		localbase pkgconfig ssl
USE_RC_SUBR=	gmid

HAS_CONFIGURE=	yes

TEST_TARGET=	regress

LDFLAGS+=	-lcrypto -lssl

USERS=		_gmid
GROUPS=		_gmid

post-build:
	${STRIP_CMD} ${WRKSRC}/gg
	${STRIP_CMD} ${WRKSRC}/gmid

post-install:
	${INSTALL_DATA} ${FILESDIR}/gmid.conf.sample \
		${STAGEDIR}${PREFIX}/etc/

.include <bsd.port.mk>
