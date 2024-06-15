PORTNAME=	container-diff
PORTVERSION=	0.19.0
DISTVERSIONPREFIX=	v
PORTREVISION=	4
CATEGORIES=	sysutils

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Diff your Docker containers
WWW=		https://github.com/GoogleContainerTools/container-diff

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	The repository has been archived by the owner on 2024-03-28. Upstream suggests diffoci as alternative
EXPIRATION_DATE=2024-06-30

USES=		go:modules

GO_MODULE=	github.com/GoogleContainerTools/container-diff

PLIST_FILES=	bin/container-diff

.include <bsd.port.mk>
