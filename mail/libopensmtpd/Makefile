PORTNAME=	libopensmtpd
DISTVERSION=	0.7
CATEGORIES=	mail
MASTER_SITES=	https://imperialat.at/releases/

MAINTAINER=	mvalleton@seos.fr
COMMENT=	Library for writing opensmtpd filters
WWW=		https://imperialat.at/dev/libopensmtpd/

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	opensmtpd>=6.6.0:mail/opensmtpd
LIB_DEPENDS=	libevent.so:devel/libevent

USES=		gmake localbase:ldflags uidfix
USE_LDCONFIG=	yes

MAKEFILE=	Makefile.gnu
MAKE_ARGS=	NEED_STRLCAT=0 \
		NEED_STRLCPY=0 \
		NEED_STRTONUM=0

# Makefile doesn't install the .so libraries or opensmtpd.h, and
# Makefile.gnu uses GNU-specific options to install, so we can't
# use either. So we just have to install the files manually then
do-install:
	${INSTALL_DATA} ${WRKSRC}/opensmtpd.h ${STAGEDIR}${PREFIX}/include/
	${INSTALL_MAN} ${WRKSRC}/osmtpd_run.3 ${STAGEDIR}${PREFIX}/share/man/man3/
	${INSTALL_LIB} ${WRKSRC}/libopensmtpd.so.0.1.0 ${STAGEDIR}${PREFIX}/lib/libopensmtpd.so.0.1.0
	${RLN} libopensmtpd.so.0.1.0 ${STAGEDIR}${PREFIX}/lib/libopensmtpd.so.0
	${RLN} libopensmtpd.so.0.1.0 ${STAGEDIR}${PREFIX}/lib/libopensmtpd.so

.include <bsd.port.mk>
