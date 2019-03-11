# Created by: past@ebs.gr
# $FreeBSD$

PORTNAME=	mgopen
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	DEBIAN/pool/main/f/fonts-mgopen
DISTNAME=	fonts-mgopen_${PORTVERSION}.orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MgOpen greek fonts collection

# almost identical to the license used in bitstream-vera
LICENSE=	MGOPEN
LICENSE_GROUPS=	FONT
LICENSE_NAME=	MgOpen Font License
LICENSE_FILE=	${FILESDIR}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		fonts tar:bzip2

NO_ARCH=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/fonts-mgopen-${PORTVERSION}/TTFs

SUB_FILES=	pkg-message

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
