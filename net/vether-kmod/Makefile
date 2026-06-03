PORTNAME=	vether-kmod
DISTVERSION=	g20211214
PORTREVISION=	1
CATEGORIES=	net

MAINTAINER=	henning.matyschok@outlook.com
COMMENT=	Virtual Ethernet Interface
WWW=		https://github.com/hmatyschok/if_vether

LICENSE=	BSD2CLAUSE ISCL
LICENSE_COMB=	multi

USES=		kmod uidfix

BROKEN_FreeBSD_15=	if_vether.c:145:16: error: incomplete definition of type 'struct ifnet'
BROKEN_FreeBSD_16=	if_vether.c:145:16: error: incomplete definition of type 'struct ifnet'

USE_GITHUB=	yes
GH_ACCOUNT=	hmatyschok
GH_PROJECT=	if_vether
GH_TAGNAME=	511ee3b393029cfff0c5b1873fe0a16f077a7459

WRKSRC_SUBDIR=	src

PLIST_FILES=	${KMODDIR}/if_vether.ko \
		share/man/man4/if_vether.4.gz \
		share/man/man4/vether.4.gz

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/man/man4
	${INSTALL_DATA} ${WRKSRC}/if_vether.4 ${STAGEDIR}${PREFIX}/share/man/man4
	@${RLN} ${STAGEDIR}${PREFIX}/share/man/man4/if_vether.4 \
		${STAGEDIR}${PREFIX}/share/man/man4/vether.4

.include <bsd.port.mk>
