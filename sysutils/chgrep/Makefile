# Ports collection makefile for:       	chgrep
# Date created:                 April 20, 2003
# Whom:                        	Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	chgrep
PORTVERSION=	1.2.2
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.bmk.bicom.pl/chgrep/
EXTRACT_SUFX=	.tgz

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Fast string substitution across multiple files

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_SIZE=	yes

MAN1=		chgrep.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/chgrep \
		${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/chgrep.1 \
		${MANPREFIX}/man/man1

.include <bsd.port.mk>
