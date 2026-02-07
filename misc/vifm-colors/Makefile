PORTNAME=	vifm-colors
DISTVERSIONPREFIX=	v
DISTVERSION=	0.13
CATEGORIES=	misc

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Various color schemes for the vifm file explorer
WWW=		https://vifm.info/colorschemes.shtml

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	vifm

NO_BUILD=	yes

SUB_FILES=	pkg-message

do-install:
	cd ${WRKSRC} && \
		${COPYTREE_SHARE} \*.vifm ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
