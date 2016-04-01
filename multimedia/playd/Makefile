# Created by: Aldis Berjoza <killasmurf86@gmail.com>
# $FreeBSD$

PORTNAME=	playd
PORTVERSION=	1.22.3
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://files.bsdroot.lv/my/FreeBSD/distfiles/
DISTNAME=	playd.sh-${PORTVERSION}

MAINTAINER=	graudeejs@gmail.com
COMMENT=	Very easy-to-use mplayer sh wrapper script (supports playlists)

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	mplayer:multimedia/mplayer

PLIST_FILES=	bin/playd \
		man/man1/playd.1.gz

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/graudeejs-playd-${REV}
REV=		1e09c80

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/playd.sh ${STAGEDIR}${PREFIX}/bin/playd
	${INSTALL_MAN} ${WRKSRC}/man/man1/playd.1 ${STAGEDIR}${PREFIX}/man/man1/

.include <bsd.port.mk>
