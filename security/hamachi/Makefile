# Created by: Lapo Luchini <lapo@lapo.it>
# $FreeBSD$

PORTNAME=	hamachi
DISTVERSION=	0.9.9.9-20
DISTVERSIONSUFFIX=	-lnx
CATEGORIES=	security linux
MASTER_SITES=	http://files.hamachi.cc/linux/
PKGNAMEPREFIX=	linux-

MAINTAINER=	lapo@lapo.it
COMMENT=	Fast, secure, simple VPN software with NAT-traversal

PATCH_DEPENDS=	upx:archivers/upx

ONLY_FOR_ARCHS=	i386 amd64
USES=		linux

USE_RC_SUBR=	hamachi
PLIST_FILES=	bin/hamachi bin/hamachi-init sbin/hamachi-tuncfg
PORTDOCS=	README CHANGES
MAKE_ENV=	HAMACHI_DST=${STAGEDIR}${PREFIX}/bin TUNCFG_DST=${STAGEDIR}${PREFIX}/sbin

post-patch:
	${RM} ${WRKSRC}/tuncfg/tuncfg
	${LOCALBASE}/bin/upx -d ${WRKSRC}/hamachi

do-build:
	${CC} ${CFLAGS} -o ${WRKSRC}/tuncfg/tuncfg ${WRKSRC}/tuncfg/tuncfg.c

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
