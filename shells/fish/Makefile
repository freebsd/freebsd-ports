PORTNAME=	fish
DISTVERSION=	3.5.0
CATEGORIES=	shells
MASTER_SITES=	https://github.com/fish-shell/fish-shell/releases/download/${PORTVERSION}/

MAINTAINER=	asomers@FreeBSD.org
COMMENT=	User friendly command line shell

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpcre2-32.so:devel/pcre2

# The python dependency is only needed by shebangfix.  At runtime python is
# only needed by some optional scripts that aren't in PATH.
USES=		cmake compiler:c++11-lang cpe localbase ncurses python:3.6+,env \
		shebangfix tar:xz
CPE_VENDOR=	fishshell
SHEBANG_FILES=	share/tools/*.py share/tools/web_config/webconfig.py

# sphinx stuff seems to be racy
MAKE_JOBS_UNSAFE=	yes

CONFLICTS_INSTALL=	comms/mlan3

MANDIRS=	${DATADIR}/man/man1

PORTDOCS=	*

OPTIONS_DEFINE=		DOCS MANPAGES NLS
OPTIONS_DEFAULT=	MANPAGES NLS
OPTIONS_SUB=		yes

NLS_USES=	gettext
NLS_CMAKE_BOOL=	WITH_GETTEXT

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MDOCS} || ${PORT_OPTIONS:MMANPAGES}
CMAKE_ARGS+=	-DBUILD_DOCS=TRUE
BUILD_DEPENDS+=	sphinx-build:textproc/py-sphinx
.endif

.if ${NCURSESBASE:M${LOCALBASE}}
CMAKE_ARGS+=	-DCURSES_NEED_NCURSES=TRUE
.endif

post-install:
.for i in fish fish_indent fish_key_reader
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${i}
.endfor
	@${MV} ${STAGEDIR}${ETCDIR}/config.fish ${STAGEDIR}${ETCDIR}/config.fish.sample

post-stage-DOCS-on:
	@${RM} ${STAGEDIR}${DOCSDIR}/.buildinfo

post-stage-MANPAGES-off:
	@${RM} -rf ${STAGEDIR}${MANPREFIX}/man/man1
	@${RM} -rf ${STAGEDIR}${DATADIR}/man

.include <bsd.port.post.mk>
