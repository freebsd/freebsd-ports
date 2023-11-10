PORTNAME=	lrcalc
PORTVERSION=	2.1
CATEGORIES=	math
MASTER_SITES=	https://bitbucket.org/asbuch/lrcalc/get/
# https://sites.math.rutgers.edu/~asbuch/lrcalc/
DISTNAME=	4c6c01f19f354c273cb16b5043928c34b1a2fb3c

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Littlewood-Richardson Calculator
WWW=		https://sites.math.rutgers.edu/~asbuch/lrcalc/

LICENSE=	GPLv2+

USES=		autoreconf libtool tar:bz2

WRKSRC=		${WRKDIR}/asbuch-lrcalc-4c6c01f19f35
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

TEST_TARGET=	check

.include <bsd.port.mk>
