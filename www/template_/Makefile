PORTNAME=	template_
PORTVERSION=	2.2.3
CATEGORIES=	www
MASTER_SITES=	http://www.xtac.net/download/?file=
DISTNAME=	Template_.2.2.3

MAINTAINER=	ports@FreeBSD.org
COMMENT=	High performance PHP compiling template engine
WWW=		https://www.xtac.net/

LICENSE=	LGPL20+

BROKEN=		Not compatible with PHP 8
DEPRECATED=	Abandonware, outdated and last version released upstream was released in 2015
EXPIRATION_DATE=2024-09-30 

FETCH_ARGS+=	-o ${DISTNAME}.tar.gz

USES=		php:web
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/tpl_plugin
.for f in Template_.class.php Template_.compiler.php
	${INSTALL_DATA} ${WRKSRC}/$f ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/tpl_plugin/* ${STAGEDIR}${DATADIR}/tpl_plugin
.endfor

.include <bsd.port.mk>
