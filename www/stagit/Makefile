# Created by: Tobias Kortkamp <t@tobik.me>
# $FreeBSD$

PORTNAME=	stagit
PORTVERSION=	0.5
CATEGORIES=	www
MASTER_SITES=	http://dl.2f30.org/releases/

MAINTAINER=	t@tobik.me
COMMENT=	Static Git page generator

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgit2.so:devel/libgit2

MAKE_ARGS=	CC="${CC}" \
		PREFIX="${PREFIX}" \
		DOCSDIR="${DOCSDIR}" \
		EXAMPLESDIR="${EXAMPLESDIR}" \
		MANPREFIX="${MANPREFIX}/man" \
		GITINC="${PREFIX}/include" \
		GITLIB="${PREFIX}/lib"

post-install:
	${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/bin/stagit \
		${STAGEDIR}${PREFIX}/bin/stagit-index

.include <bsd.port.mk>
