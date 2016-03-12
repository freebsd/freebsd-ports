# Created by: Juergen Lock <nox@jelal.kn-bremen.de>
# $FreeBSD$

PORTNAME=	cdlabelgen
PORTVERSION=	4.3.0
CATEGORIES=	print perl5
MASTER_SITES=	http://www.aczoom.com/pub/tools/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generate postscript for frontcards and traycards for CDs

USES=		perl5 tar:tgz shebangfix
SHEBANG_FILES=	cdlabelgen
NO_ARCH=	yes
NO_BUILD=	yes
MAKE_ARGS=	BASE_DIR="${STAGEDIR}${PREFIX}" \
		LIB_DIR="${STAGEDIR}${DATADIR}" \
		INSTALL="${INSTALL_SCRIPT}" \
		INSTALL_DIR="${MKDIR}" \
		INSTALL_FILE="${INSTALL_DATA}" \
		INSTALL_MAN="${INSTALL_MAN}" \
		MAN_DIR="${STAGEDIR}${PREFIX}/man"

.include <bsd.port.mk>
