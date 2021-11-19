PORTNAME=	vether-kmod
DISTVERSION=	g20211119
CATEGORIES=	net

MAINTAINER=	henning.matyschok@outlook.com
COMMENT=	Virtual Ethernet Interface

LICENSE=	BSD2CLAUSE ISCL
LICENSE_COMB=	multi

USES=		kmod uidfix

USE_GITHUB=	yes
GH_ACCOUNT=	hmatyschok
GH_PROJECT=	if_vether
GH_TAGNAME=	8fd5c68a969014fca8cc9e6e90cb686cc2b7685c

WRKSRC_SUBDIR=	src

PLIST_FILES=	${KMODDIR}/if_vether.ko \
		man/man4/if_vether.4.gz \
		man/man4/vether.4.gz

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/man/man4
	${INSTALL_DATA} ${WRKSRC}/if_vether.4 ${STAGEDIR}${PREFIX}/man/man4
	@${RLN} ${STAGEDIR}${PREFIX}/man/man4/if_vether.4 \
		${STAGEDIR}${PREFIX}/man/man4/vether.4

.include <bsd.port.mk>
