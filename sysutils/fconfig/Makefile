PORTNAME=	fconfig
PORTVERSION=	20080329
CATEGORIES=	sysutils
MASTER_SITES=	http://downloads.openwrt.org/sources/ \
		http://andrzejekiert.ovh.org/software/fconfig/

MAINTAINER=	thompsa@FreeBSD.org
COMMENT=	Read and modify RedBoot embedded boot configuration

USES=		gmake

WRKSRC=		${WRKDIR}/${PORTNAME}
PLIST_FILES=	sbin/fconfig

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fconfig ${STAGEDIR}${PREFIX}/sbin

.include <bsd.port.mk>
