# Created by: Jos Backus <jos@catnook.com>
# $FreeBSD$

PORTNAME=	mktool
PORTVERSION=	0.0.25
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.io.com/~manoj/file/

MAINTAINER=	jos@catnook.com
COMMENT=	Portable tools to manage processes and networked services

BROKEN=		Unfetchable due to MASTER_SITES reorganization
USES=		gmake
USE_BZIP2=	yes

NO_STAGE=	yes
pre-patch:
	@${REINPLACE_CMD} -e ' \
		s,^OPT=.*,OPT=${CFLAGS},; \
		s,=gcc,?=gcc,; \
		s,^bindir=.*,bindir=${PREFIX}/bin,; \
		s,cp -p,${INSTALL_PROGRAM},' ${WRKSRC}/Makefile

.include <bsd.port.mk>
