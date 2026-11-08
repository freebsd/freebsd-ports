PORTNAME=	aquantia-atlantic-kmod
PORTVERSION=	0.0.5
PORTREVISION=	3
CATEGORIES=	net

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Aquantia AQtion (Atlantic) Network Driver (Development Preview)
WWW=		https://github.com/Aquantia/aqtion-freebsd

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		kmod uidfix
USE_GITHUB=	yes

GH_ACCOUNT=	Aquantia
GH_PROJECT=	aqtion-freebsd
GH_TAGNAME=	c61d27b

PLIST_FILES=	${KMODDIR}/if_atlantic.ko

.include <bsd.port.options.mk>
.if (${OSVERSION} >= 1501502 && ${OSVERSION} < 1600000) || \
    ${OSVERSION} >= 1600008
IGNORE=		is included in the base system in FreeBSD 15.2 and later
.endif

# This patch is compliant with FreeBSD 14, but mandatory starting 15
.if ${OPSYS} == FreeBSD && (${OSVERSION} >= 1500027)
EXTRA_PATCHES+= ${FILESDIR}/extra-patch-aq__media.c
EXTRA_PATCHES+= ${FILESDIR}/extra-patch-aq__ring.c
EXTRA_PATCHES+= ${FILESDIR}/extra-patch-aq__main.c
.endif

.include <bsd.port.mk>
