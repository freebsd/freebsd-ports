# Created by: Pete Fritchman <petef@databits.net>
# $FreeBSD$

PORTNAME=	reed
PORTVERSION=	5.4
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.bayofrum.net/dist/${PORTNAME}/

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Text pager with autoscrolling and more

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		ncurses perl5 shebangfix
USE_PERL5=	run
SHEBANG_FILES=	wrap breed fix_bookmarks.pl
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	configures
CONFIGURE_ENV+=		INCDIR="${NCURSESINC}"

post-patch:
	@${REINPLACE_CMD} 's!/usr/local!${PREFIX}!g' ${WRKSRC}/configures
	@${REINPLACE_CMD} 's!sys/dir.h!dirent.h!g;\!getopt.h!d' \
		${WRKSRC}/reed.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/reed ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/breed ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/wrap ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/fix_bookmarks.pl ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/*.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
