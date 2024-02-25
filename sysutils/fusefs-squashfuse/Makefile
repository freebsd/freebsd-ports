PORTNAME=	squashfuse
PORTVERSION=	0.1.104
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/vasi/${PORTNAME}/releases/download/${DISTVERSION}/
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	jsmith@resonatingmedia.com
COMMENT=	Mount a squashfs archive and treat it like a local file system
WWW=		https://github.com/vasi/squashfuse

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		autoreconf fuse libtool pkgconfig
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
