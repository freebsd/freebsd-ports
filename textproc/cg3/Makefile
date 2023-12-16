PORTNAME=	cg3
DISTVERSION=	1.3.6
PORTREVISION=	7
CATEGORIES=	textproc
MASTER_SITES=	https://github.com/GrammarSoft/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Tools for the Constraint Grammar formalism
WWW=		https://visl.sdu.dk/constraint_grammar.html

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libboost_date_time.so:devel/boost-libs \
		libicuuc.so:devel/icu

USES=		cmake pathfix perl5 shebangfix tar:bz2
USE_LDCONFIG=	yes

SHEBANG_FILES=	scripts/cg-sort scripts/cg-strictify scripts/cg-untrace \
		scripts/cg3-autobin.pl.in

OPTIONS_DEFINE=	OPTIMIZED_CFLAGS

post-patch:
	@${REINPLACE_CMD} -e '/D_POSIX_C_SOURCE/d' \
		${WRKSRC}/CMakeLists.txt

post-patch-OPTIMIZED_CFLAGS-off:
	@${REINPLACE_CMD} -e 's| -O3||g' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
