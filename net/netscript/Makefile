# Created by: ijliao
# $FreeBSD$

PORTNAME=	netscript
PORTVERSION=	1.7.1
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	SF \
		http://fakehalo.deadpig.org/%SUBDIR%/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Portable/multi-platform lightweight TCP socket scripting

LICENSE=	PD

USES=		ncurses shebangfix tar:tgz
SHEBANG_FILES=	examples/*.ruleset examples/gui/*.ruleset \
		examples/ncurses/*.ruleset
SHEBANG_LANG=	netscript
netscript_OLD_CMD=	/usr/bin/netscript
netscript_CMD=		${LOCALBASE}/bin/netscript

CFLAGS+=	-DNCURSES -DARPA -DBSD_T -Wl,--export-dynamic
LDFLAGS+=	-lncurses

PORTDOCS=	*
PORTEXAMPLES=	*
PLIST_FILES=	bin/netscript

OPTIONS_DEFINE=	DOCS EXAMPLES GTK1

GTK1_USE=	GNOME=gtk12
GTK1_CFLAGS=	-DGTK
GTK1_CPPFLAGS=	$$(gtk-config --cflags gthread)
GTK1_LDFLAGS=	$$(gtk-config --libs gthread)

do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} ${CPPFLAGS} netscript.c \
		-o netscript ${LDFLAGS})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/netscript ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . \
		${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
