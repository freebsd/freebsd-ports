PORTNAME=	gmid
DISTVERSION=	v1.6.1
PORTREVISION=	1
CATEGORIES=	net

MAINTAINER=	freebsd@omarpolo.com
COMMENT=	Simple and secure Gemini server

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libevent.so:devel/libevent \
		libtls.so:security/libressl

USES=		localbase pkgconfig ssl
USE_GITHUB=	yes
GH_ACCOUNT=	omar-polo
USE_RC_SUBR=	gmid

HAS_CONFIGURE=	yes

TEST_TARGET=	regress

USERS=		_gmid
GROUPS=		_gmid

post-build:
	${STRIP_CMD} ${WRKSRC}/gmid

post-install:
	${INSTALL_DATA} ${FILESDIR}/gmid.conf.sample \
		${STAGEDIR}${PREFIX}/etc/

.include <bsd.port.mk>
