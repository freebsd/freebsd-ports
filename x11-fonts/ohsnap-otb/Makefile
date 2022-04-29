PORTNAME=	ohsnap-otb
DISTVERSION=	1.8.0
CATEGORIES=	x11-fonts
MASTER_SITES=	https://gitlab.com/rigoletto/${PORTNAME}/-/archive/${DISTVERSION}/

MAINTAINER=	rigoletto@FreeBSD.org
COMMENT=	Monospaced font based on Artwiz Snap

LICENSE=	GPLv2

USES=		fonts
FONTS=		ohsnap ohsnapu ohsnap.icons
NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/* ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
