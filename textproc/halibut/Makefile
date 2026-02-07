PORTNAME=	halibut
DISTVERSION=	1.3
CATEGORIES=	textproc
MASTER_SITES=	https://www.chiark.greenend.org.uk/~sgtatham/halibut/halibut-${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Free document preparation system
WWW=		https://www.chiark.greenend.org.uk/~sgtatham/halibut/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENCE

USES=		cmake cpe perl5
CPE_VENDOR=	halibut_project

CFLAGS+=	-fcommon # ld: error: duplicate symbol: all_fonts

INFO=		halibut*
PLIST_FILES=	bin/halibut \
		share/man/man1/halibut.1.gz

.include <bsd.port.mk>
