PORTNAME=	fsbackup
PORTVERSION=	1.2.1
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	http://www.opennet.ru/dev/fsbackup/src/
DISTNAME=	fsbackup-1.2pl1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	File system backup and synchronization utility

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

NO_ARCH=	yes
NO_BUILD=	yes
USES=		perl5 shebangfix

SHEBANG_FILES=	*.pl contrib/*.pl

do-install:
	cd ${WRKSRC}; ./install.pl --prefix=${PREFIX}/fsbackup --prefix-man=${MANPREFIX}/man/man1 --dest=${STAGEDIR}
	${RM} ${STAGEDIR}${PREFIX}/fsbackup/fsbackup.1

.include <bsd.port.mk>
