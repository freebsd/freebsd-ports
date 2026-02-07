PORTNAME=	agedu
PORTVERSION=	20241013.3622eda
CATEGORIES=	sysutils
MASTER_SITES=	https://www.chiark.greenend.org.uk/~sgtatham/agedu/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Unix utility for tracking down wasted disk space
WWW=		https://www.chiark.greenend.org.uk/~sgtatham/agedu/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENCE

USES=		cmake

CMAKE_OFF=	BUILD_MANPAGE
CMAKE_ON=	AGEDU_IPV4 AGEDU_IPV6

PLIST_FILES=	bin/agedu \
		share/man/man1/agedu.1.gz

.include <bsd.port.mk>
