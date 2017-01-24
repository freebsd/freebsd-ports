# $FreeBSD$

PORTNAME=	contrib
DISTVERSION=	git.2017-01-21
CATEGORIES=	sysutils
PKGNAMEPREFIX=	munin-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Contributed plugins and other for munin

RUN_DEPENDS=	munin-node>=0:sysutils/munin-node

USE_GITHUB=	yes
GH_ACCOUNT=	munin-monitoring
GH_TAGNAME=	9990b16

NO_BUILD=	yes
NO_ARCH=	yes

USES=	shebangfix uniquefiles:dirs
SHEBANG_REGEX=	./(${PORTEXAMPLES:tW:S/ /|/g})/.*
SHEBANG_LANG=	python3 expect gawk zsh
ruby_OLD_CMD=	/opt/csw/bin/ruby
zsh_CMD=	${LOCALBASE}/bin/zsh
python3_CMD=	${LOCALBASE}/bin/python${PYTHON3_DEFAULT}

# Most of the installed files are scripts, so give them a "correct" mode.
BINMODE=	755

PORTDOCS=	README.md
PORTEXAMPLES=	plugins samples templates tools

SUB_FILES=	pkg-message

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${COPYTREE_BIN} '${PORTEXAMPLES}' ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
