PORTNAME=	devctl-jail-kmod
DISTVERSION=	g20190521
CATEGORIES=	sysutils

MAINTAINER=	pizzamig@FreeBSD.org
COMMENT=	Module to expose jail lifecycle events

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=	kmod uidfix
USE_GITHUB=	yes
GH_ACCOUNT=	fubarnetes
GH_PROJECT=	kmod_devctl_jail
GH_TAGNAME=	d3c17d2381a

PLIST_FILES=	${KMODDIR}/devctl_jail.ko

.include <bsd.port.mk>
