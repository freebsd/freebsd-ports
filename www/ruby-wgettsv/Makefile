# Created by: Qing Feng <qingfeng@douban.com>
# $FreeBSD$

PORTNAME=	ruby-wgettsv
PORTVERSION=	0.95
CATEGORIES=	www ruby
MASTER_SITES=	http://alpha.mixi.co.jp/dist/tctsearch/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	wgettsv
EXTRACT_SUFX=

MAINTAINER=	qingfeng@douban.com
COMMENT=	Collect WWW resources and generate TSV data

USES=		shebangfix
SHEBANG_FILES=	wgettsv
USE_RUBY=		yes
USE_RUBY_FEATURES=	iconv
NO_WRKSUBDIR=	yes

NO_BUILD=		yes

PLIST_FILES=	bin/wgettsv

do-extract:
	@${MKDIR} ${WRKDIR}
	${CP} ${DISTDIR}/${DISTNAME} ${WRKDIR}/${DISTNAME}

do-install:
	${INSTALL_DATA} -m0755 ${WRKDIR}/${DISTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
