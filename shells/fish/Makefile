# Created by: Kai Wang <kaiw27@gmail.com>
# $FreeBSD$

PORTNAME=	fish
PORTVERSION=	3.1.1
CATEGORIES=	shells
MASTER_SITES=	https://github.com/fish-shell/fish-shell/releases/download/${PORTVERSION}/

MAINTAINER=	asomers@FreeBSD.org
COMMENT=	User friendly command line shell

LICENSE=	GPLv2

LIB_DEPENDS+=	libpcre2-32.so:devel/pcre2

# The python dependency is only needed by shebangfix.  At runtime python is
# only needed by some optional scripts that aren't in PATH.
USES=		cmake cpe ncurses python:3.4+,build \
		localbase compiler:c++11-lang shebangfix

SHEBANG_FILES=	share/tools/*.py share/tools/web_config/webconfig.py

CONFLICTS_INSTALL=	comms/mlan3

CPE_VENDOR=	fishshell

MANDIRS=	${DATADIR}/man/man1

OPTIONS_DEFAULT=	MANPAGES DOCS NLS
OPTIONS_DEFINE=	MANPAGES DOCS NLS
OPTIONS_SUB=	yes

MAKE_JOBS_UNSAFE=yes	# sphinx stuff seems to be racy
DOCS_BUILD_DEPENDS+=	sphinx-build:textproc/py-sphinx
MANPAGES_BUILD_DEPENDS+=	sphinx-build:textproc/py-sphinx
NLS_USES=		gettext
NLS_CMAKE_BOOL=		WITH_GETTEXT

PORTDOCS=	*

post-install:
.for i in fish fish_indent fish_key_reader
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${i}
.endfor

post-stage-DOCS-on:
	@${RM} ${STAGEDIR}${DOCSDIR}/.buildinfo

post-stage-MANPAGES-off:
	@${RM} -rf ${STAGEDIR}${MANPREFIX}/man/man1
	@${RM} -rf ${STAGEDIR}${DATADIR}/man

.include <bsd.port.mk>
