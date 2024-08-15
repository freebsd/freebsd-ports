PORTNAME=	hunspell
PORTVERSION=	1.7.2
PORTREVISION=	1
MASTER_SITES=	https://github.com/hunspell/hunspell/releases/download/v${PORTVERSION}/
CATEGORIES=	textproc
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Improved spell-checker for Hungarian and other languages
WWW=		https://hunspell.github.io/

LICENSE=	GPLv2+ LGPL21+ MPL11
LICENSE_COMB=	dual
LICENSE_FILE_GPLv2+ =	${_LICENSE_STORE}/GPLv2
LICENSE_FILE_LGPL21+ =	${_LICENSE_STORE}/LGPL21
LICENSE_FILE_MPL11=	${WRKSRC}/COPYING.MPL

USES=		compiler:c++11-lang cpe gettext-tools iconv libtool:keepla ncurses pathfix perl5 readline shebangfix
USE_PERL5=	run

CONFIGURE_ARGS=	--disable-nls ${ICONV_CONFIGURE_ARG} --with-readline --with-ui
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

PLIST_SUB=	SHLIB_VER=${PORTVERSION:R}

# bin/analyze
CONFLICTS_INSTALL=	tinker

CPE_VENDOR=	hunspell_project

SHEBANG_FILES=	src/tools/ispellaff2myspell

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/src/tools/hunspell.cxx

makepatch-clean:
	@${RM} ${WRKSRC}/tests/suggestiontest/Makefile.orig

.include <bsd.port.mk>

# XXX Don't override definition in Mk/bsd.port.mk
makepatch:	makepatch-clean
