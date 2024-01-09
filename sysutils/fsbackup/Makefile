PORTNAME=	fsbackup
PORTVERSION=	1.2.1
PORTREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	http://www.opennet.ru/dev/fsbackup/src/
DISTNAME=	fsbackup-1.2pl1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	File system backup and synchronization utility
WWW=		https://www.opennet.ru/dev/fsbackup/index_eng.shtml

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

NO_ARCH=	yes
NO_BUILD=	yes
USES=		perl5 shebangfix

SHEBANG_FILES=	*.pl contrib/*.pl

do-install:
	cd ${WRKSRC}; ./install.pl --prefix=${PREFIX}/fsbackup --prefix-man=${PREFIX}/share/man/man1 --dest=${STAGEDIR}
	${RM} ${STAGEDIR}${PREFIX}/fsbackup/fsbackup.1

.include <bsd.port.mk>
