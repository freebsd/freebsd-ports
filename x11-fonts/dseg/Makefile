PORTNAME=	dseg
PORTVERSION=	0.46
DISTVERSIONPREFIX=	v
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/keshikan/${PORTNAME:tu}/releases/download/${DISTVERSIONPREFIX}${PORTVERSION}/
DISTNAME=	fonts-${PORTNAME:tu}_${DISTVERSIONPREFIX}${PORTVERSION:C/\.//g}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Font family that imitates seven and fourteen segment displays

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/DSEG-LICENSE.txt

USES=		fonts zip
NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${FIND} ${WRKSRC} -name *.ttf -type f \
		-exec ${INSTALL_DATA} {} ${STAGEDIR}${FONTSDIR}/ \;

.include <bsd.port.mk>
