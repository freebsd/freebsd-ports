PORTNAME=	mime-support
PORTVERSION=	3.66
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	DEBIAN
MASTER_SITE_SUBDIR=	pool/main/m/mailcap pool/main/m/media-types
DISTFILES=	media-types_10.1.0.tar.xz mailcap_3.69.tar.xz

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	MIME Media Types list
WWW=		https://packages.qa.debian.org/m/mime-support.html

LICENSE=	PD

USES=		cpe shebangfix tar:xz

CPE_VENDOR=	debian

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/run-mailcap etc/mime.types \
		share/man/man1/run-mailcap.1.gz

SHEBANG_FILES=	mailcap/run-mailcap

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mailcap/run-mailcap ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/media-types/mime.types ${STAGEDIR}${PREFIX}/etc
	${INSTALL_MAN} ${WRKSRC}/mailcap/run-mailcap.man ${STAGEDIR}${PREFIX}/share/man/man1/run-mailcap.1

.include <bsd.port.mk>
