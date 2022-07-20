PORTNAME=	tcshrc
PORTVERSION=	1.6.2
CATEGORIES=	shells
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Set of configuration scripts for the TCSH shell

WRKSRC=		${WRKDIR}/${PORTNAME}

NO_BUILD=	yes

INSTALL_TARGET=	systeminstall
MAKE_ARGS=	BIN=${STAGEDIR}${PREFIX}/bin SHARETCSHRC=${STAGEDIR}${DATADIR}

post-patch:
	@${REINPLACE_CMD} -e 's#/usr/share#${PREFIX}/share#g' \
		${WRKSRC}/tcshrc_config

.include <bsd.port.mk>
