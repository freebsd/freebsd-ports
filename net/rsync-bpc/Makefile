# Created by: Alexander Moisseev <moiseev@mezonplus.ru>
# $FreeBSD$

PORTNAME=	rsync-bpc
PORTVERSION=	3.0.9.3
CATEGORIES=	net
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	backuppc/backuppc-beta/4.0.0alpha3

MAINTAINER=	moiseev@mezonplus.ru
COMMENT=	Modified rsync that used as part of BackupPC

LICENSE=	GPLv3

USES=		perl5
USE_PERL5=	build
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	configure.sh
CONFIGURE_ARGS=	--prefix=${PREFIX}

PLIST_FILES=	bin/rsync_bpc

.include <bsd.port.mk>
