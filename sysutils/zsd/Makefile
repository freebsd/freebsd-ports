PORTNAME=	zsd
DISTVERSION=	2025-02-23
DISTVERSIONSUFFIX=	-5243dad
CATEGORIES=	sysutils
MASTER_SITES=	https://www.fabiankeil.de/sourcecode/zfs-snapshot-destroyer/

MAINTAINER=	fk@fabiankeil.de
COMMENT=	Destroys ZFS snapshots
WWW=		https://www.fabiankeil.de/gehacktes/zsd/

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		perl5 shebangfix

SHEBANG_FILES=	zsd
NO_ARCH=	yes
NO_BUILD=	yes
PORTSCOUT=	ignore:1

PLIST_FILES=	sbin/zsd \
		share/man/man8/zsd.8.gz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/zsd ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/zsd.8 ${STAGEDIR}${PREFIX}/share/man/man8

.include <bsd.port.mk>
