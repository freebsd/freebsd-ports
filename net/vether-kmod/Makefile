# $FreeBSD$

PORTNAME=	vether-kmod
DISTVERSION=	g20180317
CATEGORIES=	net

MAINTAINER=	henning.matyschok@outlook.com
COMMENT=	Virtual Ethernet Interface

LICENSE=	BSD2CLAUSE ISCL
LICENSE_COMB=	multi

USES=		kmod uidfix

USE_GITHUB=	yes
GH_ACCOUNT=	hmatyschok
GH_PROJECT=	if_vether
GH_TAGNAME=	dc0120e9cc733a810f14a9ee7750a6775489a812

PLIST_FILES=	${KMODDIR}/if_vether.ko \
		man/man4/if_vether.4.gz \
		man/man4/vether.4.gz
WRKSRC_SUBDIR=	src

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/man/man4
	${INSTALL_DATA} ${WRKSRC}/if_vether.4 ${STAGEDIR}${PREFIX}/man/man4
	@${RLN} ${STAGEDIR}${PREFIX}/man/man4/if_vether.4 \
		${STAGEDIR}${PREFIX}/man/man4/vether.4

.include <bsd.port.mk>
