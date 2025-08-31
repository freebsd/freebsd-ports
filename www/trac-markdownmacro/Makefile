PORTNAME=	markdownmacro
PORTVERSION=	0.11.10r${REV}
PORTREVISION=	2
CATEGORIES=	www devel python
MASTER_SITES=	https://trac-hacks.org/browser/markdownmacro/
PKGNAMEPREFIX=	trac-

MAINTAINER=	samm@FreeBSD.org
COMMENT=	Table of contents macro for Trac
WWW=		https://trac-hacks.org/wiki/TocMacro

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	tracd:www/trac \
		${PYTHON_PKGNAMEPREFIX}markdown>=0:textproc/py-markdown@${PY_FLAVOR}

FETCH_BEFORE_ARGS=	-o ${DISTFILES}
REV=			18423
WRKSRC=			${WRKDIR}/trunk
USES=			python zip
USE_PYTHON=		distutils autoplist
NO_ARCH=		yes

do-fetch:
	@if [ ! -f ${DISTDIR}/${DISTFILES} ]; then \
	cd ${DISTDIR} && \
	${FETCH_CMD} ${FETCH_BEFORE_ARGS}	\
		'${MASTER_SITES}trunk?rev=${REV}&format=zip'; \
	fi

.include <bsd.port.mk>
