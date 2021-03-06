# $FreeBSD$

PORTNAME=	modernish
DISTVERSIONPREFIX=	v
DISTVERSION=	0.16.5
CATEGORIES=	shells

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	POSIX shell feature detection and language extension library

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes

NO_ARCH=	yes
NO_BUILD=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	cd ${WRKSRC} && \
	${SETENV} ${MAKE_ENV} ./install.sh -d ${PREFIX} -D ${STAGEDIR} -n -s ${SH}

	${RM} ${STAGEDIR}${DOCSDIR}/LICENSE
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR:H}
	${MV} ${STAGEDIR}${DOCSDIR}/examples ${STAGEDIR}${EXAMPLESDIR}
	${RLN} ${STAGEDIR}${EXAMPLESDIR} ${STAGEDIR}${DOCSDIR}/examples

.include <bsd.port.mk>
