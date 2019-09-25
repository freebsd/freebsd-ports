# $FreeBSD$

PORTNAME=	aquantia-atlantic-kmod
PORTVERSION=	0.0.5
CATEGORIES=	net

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Aquantia AQtion (Atlantic) Network Driver (Development Preview)

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		kmod uidfix
USE_GITHUB=	yes

GH_ACCOUNT=	Aquantia
GH_PROJECT=	aqtion-freebsd
GH_TAGNAME=	4816644

# Strip -Werror from sys/conf/kmod.mk
MAKE_ENV=	WERROR=""

PLIST_FILES=	${KMODDIR}/if_atlantic.ko

.include <bsd.port.mk>
