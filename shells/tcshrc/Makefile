# Created by: Sean Chittenden <seanc@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tcshrc
PORTVERSION=	1.6.2
CATEGORIES=	shells
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A set of configuration scripts for the TCSH shell

WRKSRC=		${WRKDIR}/${PORTNAME}

NO_BUILD=	yes

INSTALL_TARGET=	systeminstall
MAKE_ARGS=	BIN=${LOCALBASE}/bin SHARETCSHRC=${DATADIR}

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's#/usr/share#${PREFIX}/share#g' \
		${WRKSRC}/tcshrc_config

.include <bsd.port.mk>
