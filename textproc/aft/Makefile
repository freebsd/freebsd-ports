# New ports collection makefile for:	aft
# Date created:		2002/03/28
# Whom:			Alan Eldridge <alane@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	aft
PORTVERSION=	5.095
PORTEPOCH=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.maplefish.com/todd/

MAINTAINER=	yinjieh@csie.nctu.edu.tw
COMMENT=	A document preparation system using an Almost Free Text input format

USE_PERL5=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	-build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

.if defined(NOPORTDOCS)
INSTALL_TARGET=	install-binSCRIPTS install-pkgdataDATA install-pkgdataSCRIPTS
.endif

.include <bsd.port.mk>
