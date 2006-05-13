# ports collection makefile for:        mktool
# Date created:                         2002/05/28
# Whom:                                 Jos Backus <jos@catnook.com>
#
# $FreeBSD$
#

PORTNAME=	mktool
PORTVERSION=	0.0.25
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.io.com/~manoj/file/

MAINTAINER=	jos@catnook.com
COMMENT=	Portable tools to manage processes and networked services

USE_GMAKE=	yes
USE_BZIP2=	yes

pre-patch:
	@${REINPLACE_CMD} -e ' \
		s,^OPT=.*,OPT=${CFLAGS},; \
		s,=gcc,?=gcc,; \
		s,^bindir=.*,bindir=${PREFIX}/bin,; \
		s,cp -p,${INSTALL_PROGRAM},' ${WRKSRC}/Makefile

.include <bsd.port.mk>
