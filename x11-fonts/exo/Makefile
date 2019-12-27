# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	exo
PORTVERSION=	2
PORTREVISION=	2
CATEGORIES=	x11-fonts
MASTER_SITES=	http://ndiscovered.com/archives/

MAINTAINER=	pkubaj@anongoth.pl
COMMENT=	Geometric sans serif font with a technological feel

LICENSE=	OFL11

USES=		fonts zip

NO_BUILD=	yes
NO_ARCH=	yes
NO_WRKSUBDIR=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	(cd ${WRKSRC} ; ${INSTALL_DATA} *.otf ${STAGEDIR}${FONTSDIR})

.include <bsd.port.mk>
