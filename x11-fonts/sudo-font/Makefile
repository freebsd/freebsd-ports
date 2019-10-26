# $FreeBSD$

PORTNAME=	sudo-font
DISTVERSIONPREFIX=	v
DISTVERSION=	0.40
CATEGORIES=	x11-fonts
MASTER_SITES=	https://www.kutilek.de/download/ \
		https://github.com/jenskutilek/sudo-font/releases/download/${DISTVERSIONFULL}/
DISTNAME=	sudo

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Font for programmers and command line users

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/OFL.txt

USES=		fonts zip

FONTNAME=	Sudo

NO_ARCH=	yes
NO_BUILD=	yes

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/Webfonts/*.woff* ${STAGEDIR}${FONTSDIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/FONTLOG.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
