# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	findmaildirs
PORTVERSION=	0.2
CATEGORIES=	mail
MASTER_SITES=	http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Simple utility to create list of maildirs for mutt

USE_GITHUB=	yes
GH_ACCOUNT=	AMDmi3
GH_TAGNAME=	${DISTNAME}
GH_COMMIT=	dcfcea9

PLIST_FILES=	bin/${PORTNAME}

PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
