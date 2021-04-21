# Created by: Vsevolod Stakhov <vsevolod@FreeBSD.org>

PORTNAME=	clasp
PORTVERSION=	3.3.5
DISTVERSIONPREFIX=	v
CATEGORIES=	math devel

MAINTAINER=	vsevolod@FreeBSD.org
COMMENT=	Answer set solver for (extended) normal logic programs

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_sparc64=	Fails to build: internal compiler error

USES=	compiler:c++11-lang cmake

USE_GITHUB=	yes
GH_ACCOUNT=	potassco
GH_PROJECT=	${PORTNAME}
GH_TUPLE=	potassco:libpotassco:6e31cff:other/libpotassco

PLIST_FILES=	bin/${PORTNAME}

CONFLICTS_INSTALL=	clingo # bin/clasp is contained in clingo

do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
