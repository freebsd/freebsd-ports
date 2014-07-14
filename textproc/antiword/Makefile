# Created by: Yen-Ming Lee <leeym@FreeBSD.org>
# $FreeBSD$

PORTNAME=	antiword
PORTVERSION=	0.37
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.winfield.demon.nl/linux/

MAINTAINER=	leeym@FreeBSD.org
COMMENT=	An application for displaying Microsoft(R) Word documents

LICENSE=	GPLv2

USES=		gmake shebangfix
SHEBANG_FILES=	kantiword Unix-only/fontinfo.pl
MAKE_JOBS_UNSAFE=yes
INSTALL_TARGET=	global_install

PORTDOCS=	COPYING ChangeLog Emacs Exmh FAQ History Mozilla Mutt Netscape \
		QandA ReadMe antiword.1 antiword.man antiword.php testdoc.doc

CFLAGS+=	-DNDEBUG

post-patch:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${REINPLACE_CMD} \
		-e 's,/usr/local,${PREFIX},g' \
		-e 's,/usr/share,${PREFIX}/share,g'
	@${REINPLACE_CMD} -E 's|LD|CC|g; /^(CC|CFLAGS)/d' ${WRKSRC}/${MAKEFILE}
	@${TOUCH} ${WRKSRC}/fontinfo.h

post-install:
	${INSTALL_MAN} ${WRKSRC}/Docs/antiword.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/Docs && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
