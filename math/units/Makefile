PORTNAME=	units
PORTVERSION=	2.16
PORTREVISION=	3
CATEGORIES=	math
MASTER_SITES=	GNU

MAINTAINER=	jharris@widomaker.com
COMMENT=	Unit conversion and calculation
WWW=		https://www.gnu.org/software/units/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--program-prefix=g

INFO=		units

OPTIONS_DEFINE=		READLINE
OPTIONS_DEFAULT=	READLINE
READLINE_USES=	readline

post-patch:
	@${REINPLACE_CMD} -e \
	 's|$$(INSTALL_PROGRAM) units_cur|${INSTALL_SCRIPT} units_cur|' \
	${WRKSRC}/Makefile.in

.include <bsd.port.mk>
