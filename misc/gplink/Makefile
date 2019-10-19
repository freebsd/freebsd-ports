# Created by: king@v2project.com
# $FreeBSD$

PORTNAME=	gplink
PORTVERSION=	1.5
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://gp2x.org/gp32/gplink/ \
		http://www.gnu-darwin.org/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GP32 USB linker tool

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

USES=		gmake
MAKE_ARGS=	CC="${CC}" \
		CFLAGS="${CFLAGS}" \
		LDFLAGS="${LDFLAGS}"
LDFLAGS+=	-lusb
WRKSRC_SUBDIR=	src

PLIST_FILES=	bin/gplink

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gplink ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
