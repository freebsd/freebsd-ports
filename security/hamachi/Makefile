# Created by: Lapo Luchini <lapo@lapo.it>
# $FreeBSD$

PORTNAME=	hamachi
DISTVERSION=	0.9.9.9-20
DISTVERSIONSUFFIX=	-lnx
PORTREVISION=	1
CATEGORIES=	security linux
MASTER_SITES=	http://files.hamachi.cc/linux/
PKGNAMEPREFIX=	linux-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast, secure, simple VPN software with NAT-traversal

BROKEN=		fails to patch with upx 3.94
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2019-03-05
ONLY_FOR_ARCHS=	amd64 i386

PATCH_DEPENDS=	upx:archivers/upx

USES=		linux
USE_RC_SUBR=	hamachi

PLIST_FILES=	bin/hamachi bin/hamachi-init sbin/hamachi-tuncfg
PORTDOCS=	README CHANGES
MAKE_ENV=	HAMACHI_DST=${STAGEDIR}${PREFIX}/bin TUNCFG_DST=${STAGEDIR}${PREFIX}/sbin

OPTIONS_DEFINE=	DOCS

post-patch:
	${RM} ${WRKSRC}/tuncfg/tuncfg
	${LOCALBASE}/bin/upx -d ${WRKSRC}/hamachi

do-build:
	${CC} ${CFLAGS} -o ${WRKSRC}/tuncfg/tuncfg ${WRKSRC}/tuncfg/tuncfg.c

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
