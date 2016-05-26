# Created by: Tomoyuki Sakurai <tomoyukis@reallyenglish.com>
# $FreeBSD$

PORTNAME=	reallyenglish-munin-plugins
PORTVERSION=	1.3
#PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://dist.reallyenglish.com/${PORTNAME}/

MAINTAINER=	tomoyukis@reallyenglish.com
COMMENT=	3rd-party munin plugins for reallyenglish

LICENSE=	BSD

RUN_DEPENDS=	p5-libwww>0:www/p5-libwww \
	munin-node>0:sysutils/munin-node

MAKE_ARGS=	DESTDIR=${PREFIX}
SUB_FILES=	pkg-install
USES=	tar:tgz

PLIST_SUB+=	DATADIR=${DATADIR}

do-install:
	${MAKE} -C ${WRKSRC} install DESTDIR=${STAGEDIR}${PREFIX}

.include <bsd.port.mk>
