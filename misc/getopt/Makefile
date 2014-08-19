# Created by: Sergei Kolobov <sergei@kolobov.com>
# $FreeBSD$

PORTNAME=	getopt
PORTVERSION=	1.1.5
CATEGORIES=	misc
MASTER_SITES=	http://software.frodo.looijaard.name/getopt/files/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoetFreeBSD.org
COMMENT=	Replacement for getopt(1) that supports GNU-style long options

OPTIONS_DEFINE=	DOCS

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lintl
MAKE_ARGS=	CC=${CC}
MAKE_ENV=	LIBCGETOPT=0
USES=		gettext gmake

PORTDOCS=	Changelog README

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/getopt

.include <bsd.port.mk>
