# $FreeBSD$

PORTNAME=	contrib
DISTVERSION=	git.2017-10-05
CATEGORIES=	sysutils
PKGNAMEPREFIX=	munin-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Contributed plugins and other for munin

RUN_DEPENDS=	munin-node>=0:sysutils/munin-node

USES=	shebangfix uniquefiles:dirs python:env
SHEBANG_REGEX=	./(${EXAMPLES_DIRS:ts|})/.*
SHEBANG_LANG=	python3 expect gawk zsh
ruby_OLD_CMD=	/opt/csw/bin/ruby
zsh_CMD=	${LOCALBASE}/bin/zsh
python3_CMD=	${LOCALBASE}/bin/python${PYTHON3_DEFAULT}
USE_GITHUB=	yes
GH_ACCOUNT=	munin-monitoring
GH_TAGNAME=	1bba76b

NO_BUILD=	yes
NO_ARCH=	yes

# Most of the installed files are scripts, so give them a "correct" mode.
BINMODE=	755

SUB_FILES=	pkg-message

EXAMPLES_DIRS=	plugins samples templates tools

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${COPYTREE_BIN} ${EXAMPLES_DIRS:Q} ${STAGEDIR}${EXAMPLESDIR}
	@cd ${STAGEDIR}${PREFIX} && ${FIND} -f * '(' -type f -o -type l ')' >> ${TMPPLIST}

.include <bsd.port.mk>
