PORTNAME=	rge
PORTVERSION=	20251211
DISTVERSIONPREFIX=	v
CATEGORIES=	net
PKGNAMEPREFIX=	realtek-
PKGNAMESUFFIX=	-kmod

MAINTAINER=	brnrd@FreeBSD.org
COMMENT=	EXPERIMENTAL Kernel module for Realtek 8125/8126/8217 network cards
WWW=		https://github.com/erikarn/if_rge_freebsd

LICENSE=	BSD2CLAUSE

USES=		kmod tar:tgz uidfix

USE_GITHUB=	yes
GH_ACCOUNT=	erikarn
GH_PROJECT=	if_rge_freebsd
GH_TAGNAME=	aa1c088

WRKSRC_SUBDIR=	src

PLIST_FILES=	${KMODDIR}/if_rge.ko \
		share/man/man4/rge.4.gz

post-install:
	${INSTALL_MAN} ${FILESDIR}/rge.4 ${STAGEDIR}/${PREFIX}/share/man/man4

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && (${OSVERSION} < 1403000)
IGNORE=		Does not build on 13
.endif

.include <bsd.port.mk>
