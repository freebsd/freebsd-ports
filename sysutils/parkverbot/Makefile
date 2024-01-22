PORTNAME=	parkverbot
PORTVERSION=	1.5
CATEGORIES=	sysutils
MASTER_SITES=	https://inai.de/files/parkverbot/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Hard disk head parking inhibitor
WWW=		https://inai.de/projects/parkverbot/

LICENSE=	GPLv2+

LIB_DEPENDS=	libHX.so:lang/libhx

USES=		pkgconfig tar:xz
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

PLIST_FILES=	share/man/man8/parkverbot.8.gz sbin/parkverbot

post-install:
	${RM} -r ${STAGEDIR}/lib/systemd

.include <bsd.port.mk>
