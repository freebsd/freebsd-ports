PORTNAME=	fuzzysearchdatabase
PORTVERSION=	g20201005
CATEGORIES=	textproc devel
MASTER_SITES=	https://bitbucket.org/${BB_ACCOUNT}/${BB_PROJECT}/get/${BB_COMMIT}.tar.gz?dummy=/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ single-header simple "fuzzy" search library

LICENSE=	BSD3CLAUSE

BB_ACCOUNT=	j_norberg
BB_PROJECT=	${PORTNAME}
BB_COMMIT=	fe62479811e5

WRKSRC=		${WRKDIR}/${BB_ACCOUNT}-${BB_PROJECT}-${BB_COMMIT}

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	include/FuzzySearchDatabase.hpp

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/FuzzySearchDatabase.hpp ${STAGEDIR}${PREFIX}/include

.include <bsd.port.mk>
