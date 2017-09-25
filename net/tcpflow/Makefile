# Created by: Jose M. Alcaide <jose@we.lc.ehu.es>
# $FreeBSD$

PORTNAME=	tcpflow
PORTVERSION=	1.4.5
PORTREVISION=	4
CATEGORIES=	net
MASTER_SITES=	http://digitalcorpora.org/downloads/${PORTNAME}/

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Program that captures data transmitted as part of TCP connections

LICENSE=	GPLv3

BUILD_DEPENDS=	${LOCALBASE}/include/boost/icl/interval.hpp:devel/boost-libs
LIB_DEPENDS=	libcairo.so:graphics/cairo

USES=		ssl
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_lib_md_MD5=no \
		ac_cv_header_tre_tre_h=no ac_cv_lib_tre_tre_regcomp=no \
		ac_cv_header_sqlite3_h=no ac_cv_lib_sqlite3_sqlite3_libversion=no
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

PLIST_FILES=	bin/tcpflow man/man1/tcpflow.1.gz
PORTDOCS=	AUTHORS ChangeLog NEWS README

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
