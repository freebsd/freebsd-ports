# Created by: Sergei Kolobov <sergei@kolobov.com>
# $FreeBSD$

PORTNAME=	getopt
PORTVERSION=	1.1.6
CATEGORIES=	misc
MASTER_SITES=	http://frodo.looijaard.name/system/files/software/getopt/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Replacement for getopt(1) that supports GNU-style long options

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

MAKE_ARGS=	CC=${CC} LIBCGETOPT=0
USES=		gmake

PORTDOCS=	Changelog README

NLS_CFLAGS=		-I${LOCALBASE}/include
NLS_MAKE_ARGS=		WITHOUT_GETTEXT=0
NLS_MAKE_ARGS_OFF=	WITHOUT_GETTEXT=1
NLS_LDFLAGS=		-L${LOCALBASE}/lib -lintl
NLS_USES=		gettext

post-patch:
	@${RM} ${WRKSRC}/gnu/*.o

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/getopt

.include <bsd.port.mk>
