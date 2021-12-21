# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	agedu
PORTVERSION=	20211129.8cd63c5
CATEGORIES=	sysutils
MASTER_SITES=	https://www.chiark.greenend.org.uk/~sgtatham/agedu/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Unix utility for tracking down wasted disk space

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENCE

USES=		cmake

CMAKE_OFF=	BUILD_MANPAGE
CMAKE_ON=	AGEDU_IPV4 AGEDU_IPV6

PLIST_FILES=	bin/agedu \
		man/man1/agedu.1.gz

.include <bsd.port.mk>
