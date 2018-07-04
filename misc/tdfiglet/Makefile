# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tdfiglet
PORTVERSION=	0.0.0.1
CATEGORIES=	misc

MAINTAINER=	zi@FreeBSD.org
COMMENT=	A figlet for TDF ANSI fonts

USES=		gmake
ALL_TARGET=	default

USE_GITHUB=	yes
GH_ACCOUNT=	tat3r
GH_TAGNAME=	b0860ce
#GH_TAGNAME=	b0860ceca3f8d7fa9e3fa8180a0e491d06494afe

post-patch:
	@${REINPLACE_CMD} -e "s,fonts,${DATADIR}," ${WRKSRC}/${PORTNAME}.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	(cd ${WRKSRC}/fonts && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
