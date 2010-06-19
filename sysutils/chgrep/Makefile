# Ports collection makefile for:       	chgrep
# Date created:                 April 20, 2003
# Whom:                        	Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	chgrep
PORTVERSION=	1.2.4
CATEGORIES=	sysutils
MASTER_SITES=	http://www.bmk-it.com/projects/chgrep/files/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast string substitution across multiple files

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAN1=		chgrep.1
PLIST_FILES=	bin/chgrep

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/chgrep \
		${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/chgrep.1 \
		${MANPREFIX}/man/man1

.include <bsd.port.mk>
