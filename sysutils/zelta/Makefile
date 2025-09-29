PORTNAME=	zelta
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	daniel@belltech.it
COMMENT=	ZFS tools used for data migration and backup management
WWW=		https://github.com/bellhyve/zelta

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	bellhyve

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

_ZELTA_SHARE=	${PREFIX}/share/zelta
_ZELTA_CONF=	zelta.conf
_ZELTA_ENV=	zelta.env

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/zelta ${STAGEDIR}${PREFIX}/bin
	${RLN} ${STAGEDIR}${PREFIX}/bin/zelta ${STAGEDIR}${PREFIX}/bin/zeport
	${RLN} ${STAGEDIR}${PREFIX}/bin/zelta ${STAGEDIR}${PREFIX}/bin/zmatch
	${RLN} ${STAGEDIR}${PREFIX}/bin/zelta ${STAGEDIR}${PREFIX}/bin/zpull
	${RLN} ${STAGEDIR}${PREFIX}/bin/zelta ${STAGEDIR}${PREFIX}/bin/zsync
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/${_ZELTA_ENV} ${STAGEDIR}${ETCDIR}/${_ZELTA_ENV}.sample
	${INSTALL_DATA} ${WRKSRC}/${_ZELTA_CONF} ${STAGEDIR}${ETCDIR}/${_ZELTA_CONF}.sample
	${MKDIR} ${STAGEDIR}${_ZELTA_SHARE}
	${INSTALL_SCRIPT} ${WRKSRC}/share/zelta/* ${STAGEDIR}${_ZELTA_SHARE}
	${INSTALL_MAN} ${WRKSRC}/doc/*.8 ${STAGEDIR}${PREFIX}/share/man/man8

.include <bsd.port.mk>
