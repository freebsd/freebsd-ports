PORTNAME=	cg3
PORTVERSION=	1.3.6
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Tools for the Constraint Grammar formalism

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libboost_date_time.so:devel/boost-libs \
		libicuuc.so:devel/icu

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	GrammarSoft
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e '/D_POSIX_C_SOURCE/d' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
