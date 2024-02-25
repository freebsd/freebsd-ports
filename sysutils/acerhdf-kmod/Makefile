PORTNAME=	acerhdf-kmod
DISTVERSION=	0.1.4
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://codeberg.org/attachments/c87b1205-eb13-4500-8066-254e7237277b?dummy=/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Acer Aspire One fan control
WWW=		https://codeberg.org/tobik/acerhdf-kmod

LICENSE=	GPLv2

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	specific to one machine

USES=		kmod uidfix

post-install:
	${INSTALL_MAN} ${WRKSRC}/acerhdf.4 ${STAGEDIR}${PREFIX}/share/man/man4

.include <bsd.port.mk>
