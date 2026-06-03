PORTNAME=	units
DISTVERSION=	2.27
CATEGORIES=	math
MASTER_SITES=	GNU

MAINTAINER=	jharris@widomaker.com
COMMENT=	Unit conversion and calculation
WWW=		https://www.gnu.org/software/units/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=g --sharedstatedir=${PREFIX}/share

INFO=		units

OPTIONS_DEFINE=		READLINE UNITS_CUR
OPTIONS_DEFAULT=	READLINE
OPTIONS_SUB=		yes
UNITS_CUR_DESC=		Include gunits_cur(8) for updating currency exchange rates
READLINE_USES=		readline
UNITS_CUR_USES=			python shebangfix
UNITS_CUR_MAKE_ARGS=		HAVE_PYTHON=yes
UNITS_CUR_MAKE_ARGS_OFF=	HAVE_PYTHON=no
UNITS_CUR_VARS=			SHEBANG_FILES=units_cur

post-patch:
	@${REINPLACE_CMD} -e \
	 's|$$(INSTALL_PROGRAM) units_cur|${INSTALL_SCRIPT} units_cur|' \
	${WRKSRC}/Makefile.in

.include <bsd.port.mk>
