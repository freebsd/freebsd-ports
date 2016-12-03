# Created by: janos.mohacsi@bsd.hu
# $FreeBSD$

PORTNAME=	hunspell
PORTVERSION=	1.5.4
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc

MAINTAINER=	office@FreeBSD.org
COMMENT=	Improved spell-checker for Hungarian and other languages

LICENSE=	GPLv2 LGPL21 MPL
LICENSE_COMB=	dual
LICENSE_FILE_LGPL21=	${WRKSRC}/COPYING.LGPL
LICENSE_FILE_MPL=	${WRKSRC}/COPYING.MPL

CONFLICTS_INSTALL=	tinker-[0-9]*
CONFIGURE_ARGS=	--disable-nls ${ICONV_CONFIGURE_ARG} --with-readline --with-ui
GNU_CONFIGURE=	yes
USES=		libtool:keepla pathfix iconv ncurses readline shebangfix perl5
USE_GITHUB=	yes
SHEBANG_FILES=	src/tools/ispellaff2myspell
USE_LDCONFIG=	yes
USE_PERL5=	run
INSTALL_TARGET=	install-strip

PLIST_SUB=	SHLIB_VER=${PORTVERSION:R}

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/src/tools/hunspell.cxx

.include <bsd.port.mk>
