# $FreeBSD$

PORTNAME=	vether-kmod
DISTVERSION=	g20180312
CATEGORIES=	net

MAINTAINER=	henning.matyschok@outlook.com
COMMENT=	Virtual Ethernet Interface

LICENSE=	BSD2CLAUSE ISCL
LICENSE_COMB=	multi

USES=		kmod uidfix

USE_GITHUB=	yes
GH_ACCOUNT=	hmatyschok
GH_PROJECT=	if_vether
GH_TAGNAME=	4cd710c13f51dcba488c8857e7bf938ca4022be7

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
