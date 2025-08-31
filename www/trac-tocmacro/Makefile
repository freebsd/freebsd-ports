PORTNAME=	tocmacro
PORTVERSION=	12.0.0r${REV}
PORTREVISION=	2
CATEGORIES=	www devel python
MASTER_SITES=	https://trac-hacks.org/browser/tocmacro/
PKGNAMEPREFIX=	trac-

MAINTAINER=	samm@FreeBSD.org
COMMENT=	Table of contents macro for Trac
WWW=		https://trac-hacks.org/wiki/TocMacro

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	tracd:www/trac

FETCH_BEFORE_ARGS=	-o ${DISTFILES}
REV=			18149
WRKSRC=			${WRKDIR}/0.11
USES=			python zip
USE_PYTHON=		distutils autoplist
NO_ARCH=		yes

do-fetch:
	@if [ ! -f ${DISTDIR}/${DISTFILES} ]; then \
	cd ${DISTDIR} && \
	${FETCH_CMD} ${FETCH_BEFORE_ARGS}	\
		'${MASTER_SITES}0.11?rev=${REV}&format=zip'; \
	fi

.include <bsd.port.mk>
