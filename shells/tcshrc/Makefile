# New ports collection makefile for:	tcshrc
# Date created:		2003-09-09
# Whom:			Sean Chittenden <seanc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tcshrc
PORTVERSION=	1.2.0
PORTREVISION=	1
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	tcshrc

MAINTAINER=	seanc@FreeBSD.org
COMMENT=	A set of configuration scripts for the TCSH shell

USE_REINPLACE=	YES

INSTALL_TARGET=	systeminstall
MAKE_ARGS=	BIN=${LOCALBASE}/bin SHARETCSHRC=${DATADIR}

WRKSRC=	${WRKDIR}/${PORTNAME}

do-build:
	${REINPLACE_CMD} -e 's#/usr/share#${PREFIX}/share#g' ${WRKSRC}/tcsh_config

.include <bsd.port.mk>
