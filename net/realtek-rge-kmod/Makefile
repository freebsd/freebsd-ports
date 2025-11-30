PORTNAME=	rge
PORTVERSION=	20251129
DISTVERSIONPREFIX=	v
CATEGORIES=	net
PKGNAMEPREFIX=	realtek-
PKGNAMESUFFIX=	-kmod

MAINTAINER=	brnrd@FreeBSD.org
COMMENT=	EXPERIMENTAL Kernel module for Realtek 8125/8126/8217 network cards
WWW=		https://github.com/erikarn/if_rge_freebsd

LICENSE=	BSD

USES=		kmod tar:tgz uidfix

USE_GITHUB=	yes
GH_ACCOUNT=	erikarn
GH_PROJECT=	if_rge_freebsd
GH_TAGNAME=	d05b7b5

WRKSRC_SUBDIR=	src

PLIST_FILES=	${KMODDIR}/if_rge.ko \
		share/man/man4/rge.4.gz

post-install:
	${INSTALL_MAN} ${FILESDIR}/rge.4 ${STAGEDIR}/${PREFIX}/share/man/man4

.include <bsd.port.mk>
