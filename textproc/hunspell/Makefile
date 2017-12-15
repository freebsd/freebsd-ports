# Created by: janos.mohacsi@bsd.hu
# $FreeBSD$

PORTNAME=	hunspell
PORTVERSION=	1.6.2
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Improved spell-checker for Hungarian and other languages

LICENSE=	GPLv2+ LGPL21+ MPL11
LICENSE_COMB=	dual
LICENSE_FILE_GPLv2+ =	${_LICENSE_STORE}/GPLv2
LICENSE_FILE_LGPL21+ =	${_LICENSE_STORE}/LGPL21
LICENSE_FILE_MPL11=	${WRKSRC}/COPYING.MPL

CONFLICTS_INSTALL=	tinker-[0-9]*
CONFIGURE_ARGS=	--disable-nls ${ICONV_CONFIGURE_ARG} --with-readline --with-ui
GNU_CONFIGURE=	yes
USES=		autoreconf compiler:c++11-lib libtool:keepla pathfix \
		iconv ncurses readline shebangfix perl5
USE_GITHUB=	yes
SHEBANG_FILES=	src/tools/ispellaff2myspell
USE_LDCONFIG=	yes
USE_PERL5=	run
INSTALL_TARGET=	install-strip

PLIST_SUB=	SHLIB_VER=${PORTVERSION:R}

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/src/tools/hunspell.cxx

makepatch-clean:
	@${RM} ${WRKSRC}/tests/suggestiontest/Makefile.orig

.include <bsd.port.mk>

# XXX Don't override definition in Mk/bsd.port.mk
makepatch:	makepatch-clean
