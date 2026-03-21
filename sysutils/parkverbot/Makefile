PORTNAME=	parkverbot
PORTVERSION=	1.6
CATEGORIES=	sysutils
MASTER_SITES=	https://inai.de/files/parkverbot/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Hard disk head parking inhibitor
WWW=		https://inai.de/projects/parkverbot/

LICENSE=	GPLv2+

LIB_DEPENDS=	libHX.so:lang/libhx

USES=		pkgconfig tar:zst
GNU_CONFIGURE=	yes
USE_RC_SUBR=	${PORTNAME}

PLIST_FILES=	sbin/parkverbot share/man/man8/parkverbot.8.gz

post-install:
	${RM} -r ${STAGEDIR}/lib/systemd

.include <bsd.port.mk>
