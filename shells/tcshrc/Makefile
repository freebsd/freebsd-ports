# New ports collection makefile for:	tcshrc
# Date created:				2003-09-09
# Whom:					Sean Chittenden <seanc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tcshrc
PORTVERSION=	1.6.0
PORTREVISION=	1
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	tcshrc

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A set of configuration scripts for the TCSH shell

NO_BUILD=	yes

INSTALL_TARGET=	systeminstall
MAKE_ARGS=	BIN=${LOCALBASE}/bin SHARETCSHRC=${DATADIR}

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's#/usr/share#${PREFIX}/share#g' \
		${WRKSRC}/tcshrc_config

.include <bsd.port.mk>
