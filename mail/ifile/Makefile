# New ports collection makefile for:	ifile
# Date created:         29 Jan 2002
# Whom:                 David Bushong <david+ports@bushong.net>
#
# $FreeBSD$
#

PORTNAME=	ifile
PORTVERSION=	1.3.8
CATEGORIES=	mail textproc
MASTER_SITES=	http://people.csail.mit.edu/jrennie/ifile/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An application of machine learning to e-mail filtering

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=		ifile.1
PLIST_FILES=	bin/ifile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ifile ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ifile.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
