# Created by: Qing Feng <qingfeng@douban.com>
# $FreeBSD$

PORTNAME=	wgettsv
PORTVERSION=	0.95
PORTREVISION=	1
CATEGORIES=	www ruby
MASTER_SITES=	http://alpha.mixi.co.jp/dist/tctsearch/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	wgettsv
EXTRACT_SUFX=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Collect WWW resources and generate TSV data

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USES=		shebangfix
USE_RUBY=		yes
SHEBANG_FILES=	wgettsv

PLIST_FILES=	bin/wgettsv

do-extract:
	@${MKDIR} ${WRKDIR}
	${CP} ${DISTDIR}/${DISTNAME} ${WRKDIR}/${DISTNAME}

do-install:
	${INSTALL_DATA} -m0755 ${WRKDIR}/${DISTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
