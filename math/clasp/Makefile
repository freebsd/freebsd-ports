# Created by: Vsevolod Stakhov <vsevolod@FreeBSD.org>
# $FreeBSD$

PORTNAME=	clasp
PORTVERSION=	3.1.3
CATEGORIES=	math devel
MASTER_SITES=	SOURCEFORGE/potassco/${PORTNAME}/${PORTVERSION}
EXTRACT_SUFX=	-source.tar.gz

MAINTAINER=	vsevolod@FreeBSD.org
COMMENT=	Answer set solver for (extended) normal logic programs

BROKEN_sparc64=	Fails to build: internal compiler error

USES=	cmake

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
