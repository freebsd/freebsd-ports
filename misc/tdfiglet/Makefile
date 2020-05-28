# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tdfiglet
PORTVERSION=	0.5
CATEGORIES=	misc

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Figlet for TDF ANSI fonts

USES=		gmake
ALL_TARGET=	default

USE_GITHUB=	yes
GH_ACCOUNT=	tat3r

post-patch:
	@${REINPLACE_CMD} -Ee "s,^(FONTDIR := ).*,\1${DATADIR}," ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	(cd ${WRKSRC}/fonts && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
