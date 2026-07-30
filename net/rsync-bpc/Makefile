PORTNAME=	rsync-bpc
PORTVERSION=	3.1.3.2
CATEGORIES=	net

MAINTAINER=	moiseev@mezonplus.ru
COMMENT=	Modified rsync that used as part of BackupPC
WWW=		https://backuppc.sourceforge.net/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		perl5 ssl

USE_GITHUB=	yes
GH_ACCOUNT=	backuppc

USE_PERL5=	build
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	configure.sh
CONFIGURE_ARGS=	--prefix=${PREFIX}
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--disable-lz4 --disable-md2man --disable-xxhash --disable-zstd

PLIST_FILES=	bin/rsync_bpc

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/rsync_bpc

.include <bsd.port.mk>
