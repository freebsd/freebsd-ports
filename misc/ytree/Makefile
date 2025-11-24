PORTNAME=	ytree
DISTVERSION=	2.10
CATEGORIES=	misc
MASTER_SITES=	http://www.han.de/~werner/

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	DOS-XTREE(tm) look-a-like file manager
WWW=		https://www.han.de/~werner/ytree.html

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		localbase ncurses readline
ALL_TARGET=	ytree
LDFLAGS+=	-lreadline

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ytree ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/ytree.conf ${STAGEDIR}${PREFIX}/etc/ytree.conf.sample
	${INSTALL_MAN} ${WRKSRC}/ytree.1 ${STAGEDIR}${PREFIX}/share/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/ytree
.for file in CHANGES README THANKS
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${PREFIX}/share/doc/ytree
.endfor

.include <bsd.port.mk>
