# Created by: vanilla@
# $FreeBSD$

PORTNAME=	xqilla
PORTVERSION=	2.3.3
PORTEPOCH=	1
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}
DISTNAME=	XQilla-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XQuery and XPath2 library

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libxerces-c.so:textproc/xerces-c3 \
		libtidy.so:www/tidy-lib

USES=		libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-xerces=${LOCALBASE} \
		--with-faxpp=no \
		--with-tidy=${LOCALBASE}
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

OPTIONS_DEFINE=		DOXYGEN

DOCYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen \
			dot:graphics/graphviz
DOCYGEN_ALL_TARGET=	all docs

post-patch:
	@${REINPLACE_CMD} -e \
		's|[[:blank:]]-R$$(xerces_lib)||' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's|[[:blank:]]-R$$with_.*"|"|' ${WRKSRC}/configure

post-install-DOXYGEN-on:
	@(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} "*-api" \
		${STAGEDIR}${DOCSDIR})
	@(cd ${STAGEDIR}${PREFIX} && ${FIND} ${DOCSDIR:S|${PREFIX}/||} \
		! -type d >> ${TMPPLIST})

.include <bsd.port.mk>
