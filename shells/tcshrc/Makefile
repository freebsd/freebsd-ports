PORTNAME=	tcshrc
PORTVERSION=	1.6.2
CATEGORIES=	shells
MASTER_SITES=	SF

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Set of configuration scripts for the TCSH shell
WWW=		https://tcshrc.sourceforge.net/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

MAKE_ARGS=	BIN=${STAGEDIR}${PREFIX}/bin SHARETCSHRC=${STAGEDIR}${DATADIR}
INSTALL_TARGET=	systeminstall

NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's#/usr/share#${PREFIX}/share#g' \
		${WRKSRC}/tcshrc_config

.include <bsd.port.mk>
