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

NLS_MAKE_ARGS=		WITHOUT_GETTEXT=0
NLS_MAKE_ARGS_OFF=	WITHOUT_GETTEXT=1
NLS_LDFLAGS=		-lintl
NLS_USES=		gettext localbase

post-patch:
	@${RM} ${WRKSRC}/gnu/*.o

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/getopt

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
