# $FreeBSD$

PORTNAME=	gophernicus
DISTVERSION=	3.0.1
CATEGORIES=	www

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Modern full-featured and secure Gopher daemon

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
MAKE_ARGS=	CC="${CC}" \
		INSTALL=${INSTALL} \
		SBINDIR=${STAGEDIR}${PREFIX}/sbin
INSTALL_TARGET=	install-files
SUB_FILES=	pkg-message

PLIST_FILES=	sbin/gophernicus
PORTDOCS=	README.Gophermap README.md changelog gophermap gophertag

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && \
		${INSTALL_MAN} ${PORTDOCS} \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
