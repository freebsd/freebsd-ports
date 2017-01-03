# Created by: Tobias Kortkamp <tobias.kortkamp@gmail.com>
# $FreeBSD$

PORTNAME=	acerhdf-kmod
PORTVERSION=	0.1.2
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	t@tobik.me
COMMENT=	Acer Aspire One fan control

LICENSE=	GPLv2

USES=		kmod uidfix
KMODNAME=	acerhdf
KERN_DEBUGDIR=
MANDIR=		${PREFIX}/man/man4

USE_GITHUB=	yes
GH_PROJECT=	kmod-acerhdf
GH_ACCOUNT=	t6

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	specific to one machine

post-install:
	${INSTALL_MAN} ${WRKSRC}/${KMODNAME}.4 ${STAGEDIR}${MANDIR}

.include <bsd.port.mk>
