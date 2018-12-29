# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	makiki
PORTVERSION=	0.3
DISTVERSIONPREFIX=	release_
CATEGORIES=	www scheme
PKGNAMEPREFIX=	gauche-

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Simple multithreaded HTTP server written in Gauche

LICENSE=	BSD

BUILD_DEPENDS=	gosh:lang/gauche
RUN_DEPENDS=	gosh:lang/gauche

HAS_CONFIGURE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	shirok
GH_PROJECT=	Gauche-makiki

GUILE_SITELIBDIR_REL=	${:!gauche-config --sitelibdir!:S,^${PREFIX}/,,}

EXAMPLESDIR=	${PREFIX}/share/examples/gauche/${PORTNAME}

PLIST_FILES=	${GUILE_SITELIBDIR_REL}/.packages/Gauche-makiki.gpd \
		${GUILE_SITELIBDIR_REL}/makiki/cgi.scm \
		${GUILE_SITELIBDIR_REL}/makiki/connect.scm \
		${GUILE_SITELIBDIR_REL}/makiki.scm
PORTEXAMPLES=	*

OPTIONS_DEFINE=	EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e 's,0\.2,${PORTVERSION},' ${WRKSRC}/package.scm

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
