PORTNAME=	condy
DISTVERSION=	3.2
CATEGORIES=	sysutils

MAINTAINER=	dteske@FreeBSD.org
COMMENT=	Conky launcher and wallpaper rotator

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	conky:sysutils/conky \
		hsetroot:x11/hsetroot

USES=		python:build
USE_GITHUB=	yes
GH_ACCOUNT=	FrauBSD

# PYTHON= drives the sample wallpaper build (no bare python3 on PATH).
MAKE_ARGS=	PREFIX="${PREFIX}" \
		PYTHON="${PYTHON_CMD}"

NO_ARCH=	yes

OPTIONS_DEFINE=		DOCS EXAMPLES
OPTIONS_DEFAULT=	DOCS EXAMPLES
OPTIONS_SUB=		yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/condy ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_MAN} ${WRKSRC}/condy.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${MKDIR} ${STAGEDIR}${PREFIX}/etc
	${INSTALL_DATA} ${WRKSRC}/samples/condy.conf \
		${STAGEDIR}${PREFIX}/etc/condy.conf.sample

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG.md ${WRKSRC}/README.md \
		${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "theme autostart" \
		${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/condy.conf \
		${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
