# Created by: Sergei Kolobov <sergei@kolobov.com>
# $FreeBSD$

PORTNAME=	getopt
PORTVERSION=	1.1.5
CATEGORIES=	misc
MASTER_SITES=	http://software.frodo.looijaard.name/getopt/files/

MAINTAINER=	eadler@FreeBSD.org
COMMENT=	Replacement for getopt(1) that supports GNU-style long options

USES=		gettext gmake

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lintl
MAKE_ENV+=	LIBCGETOPT=0

DOCS=		Changelog README

post-patch:
	${REINPLACE_CMD} -e 's|CC=gcc|CC=${CC}|' ${WRKSRC}/Makefile

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
