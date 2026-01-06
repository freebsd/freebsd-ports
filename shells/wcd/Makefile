PORTNAME=	wcd
DISTVERSION=	6.0.6
CATEGORIES=	shells
MASTER_SITES=	SF

MAINTAINER=	jishanalam9128@gmail.com
COMMENT=	Command-line program to change directory fast
WWW=		http://wcd.sourceforge.net/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/doc/copying.txt

USES=		gmake ncurses
MAKE_ARGS=	docsubdir=${PORTNAME} \
		EXT= \
		LIB_CURSES=-l${NCURSES_IMPL} \
		mandir=${PREFIX}/share/man \
		PREFIX=${PREFIX}
CFLAGS+=	-I${NCURSESINC}

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_MAKE_ARGS_OFF=	ENABLE_NLS=

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/src/Makefile

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
