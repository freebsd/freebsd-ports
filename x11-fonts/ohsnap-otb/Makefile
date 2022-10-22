PORTNAME=	ohsnap-otb
DISTVERSION=	1.8.0
CATEGORIES=	x11-fonts
PORTREVISION=	1

MAINTAINER=	rigoletto@FreeBSD.org
COMMENT=	Monospaced font based on Artwiz Snap
WWW=		https://gitlab.com/rigoletto/ohsnap-otb

LICENSE=	GPLv2

USES=		fonts

USE_GITLAB=	yes
GL_ACCOUNT=	rigoletto
GL_COMMIT=	c88223abc6fcb4c5970d8ed6c3887ed8a1ab0817

FONTS=		ohsnap ohsnapu ohsnap.icons
NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/* ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
