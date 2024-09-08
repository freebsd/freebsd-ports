PORTNAME=	gmid
DISTVERSION=	2.1.1
CATEGORIES=	net
MASTER_SITES=	https://github.com/omar-polo/${PORTNAME}/releases/download/${DISTVERSION}/ \
		https://ftp.omarpolo.com/

MAINTAINER=	freebsd@omarpolo.com
COMMENT=	Simple and secure Gemini server
WWW=		https://gmid.omarpolo.com

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libevent.so:devel/libevent

USES=		localbase pkgconfig ssl
USE_RC_SUBR=	gmid

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc

TEST_TARGET=	regress

USERS=		_gmid
GROUPS=		_gmid

post-patch:
	@${REINPLACE_CMD} -e 's|/man|/share/man|' ${WRKSRC}/configure

post-install:
	${INSTALL_DATA} ${FILESDIR}/gmid.conf.sample \
		${STAGEDIR}${PREFIX}/etc/
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/gemexp
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/gg
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/gmid
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/titan

.include <bsd.port.mk>
