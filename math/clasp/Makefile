PORTNAME=	clasp
PORTVERSION=	3.3.9
DISTVERSIONPREFIX=	v
CATEGORIES=	math devel

MAINTAINER=	vsevolod@FreeBSD.org
COMMENT=	Answer set solver for (extended) normal logic programs
WWW=		https://potassco.org/clasp/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=	compiler:c++11-lang cmake

USE_GITHUB=	yes
GH_ACCOUNT=	potassco
GH_TUPLE=	potassco:libpotassco:fa39da4:other/libpotassco

PLIST_FILES=	bin/${PORTNAME}

CONFLICTS_INSTALL=	clingo # bin/clasp is contained in clingo

do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
