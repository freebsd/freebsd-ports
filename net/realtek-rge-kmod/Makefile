PORTNAME=	rge
PORTVERSION=	20260706
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	net
PKGNAMEPREFIX=	realtek-
PKGNAMESUFFIX=	-kmod

MAINTAINER=	brnrd@FreeBSD.org
COMMENT=	EXPERIMENTAL Kernel module for Realtek 8125/8126/8217 network cards
WWW=		https://github.com/erikarn/if_rge_freebsd

#DEPRECATED=	This port will be removed when FreeBSD 14 is end-of-life
#EXPIRATION_DATE=2028-11-30

LICENSE=	BSD2CLAUSE

USES=		kmod tar:tgz uidfix

USE_GITHUB=	yes
GH_ACCOUNT=	erikarn
GH_PROJECT=	if_rge_freebsd
GH_TAGNAME=	dd139174b854a403cbf9243ed13ef440557aa24d

WRKSRC_SUBDIR=	src

PLIST_FILES=	${KMODDIR}/if_rge.ko \
		share/man/man4/rge.4.gz

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1502000
IGNORE=		Use rge(4) from FreeBSD base
.endif

post-install:
	${INSTALL_MAN} ${FILESDIR}/rge.4 ${STAGEDIR}/${PREFIX}/share/man/man4

.include <bsd.port.post.mk>
