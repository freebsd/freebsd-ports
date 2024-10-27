PORTNAME=	squashfuse
PORTVERSION=	0.5.2
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/vasi/${PORTNAME}/releases/download/${DISTVERSION}/
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	jsmith@resonatingmedia.com
COMMENT=	Mount a squashfs archive and treat it like a local file system
WWW=		https://github.com/vasi/squashfuse

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfuse3.so:sysutils/fusefs-libs3

USES=		autoreconf fuse libtool pkgconfig
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

.include <bsd.port.mk>
