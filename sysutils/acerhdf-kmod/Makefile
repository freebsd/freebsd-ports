# Created by: Tobias Kortkamp <tobias.kortkamp@gmail.com>
# $FreeBSD$

PORTNAME=	acerhdf-kmod
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.3
CATEGORIES=	sysutils

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Acer Aspire One fan control

LICENSE=	GPLv2

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	specific to one machine

USES=		kmod uidfix
USE_GITHUB=	yes
GH_ACCOUNT=	t6
GH_PROJECT=	kmod-acerhdf

post-install:
	${INSTALL_MAN} ${WRKSRC}/acerhdf.4 ${STAGEDIR}${PREFIX}/man/man4

.include <bsd.port.mk>
