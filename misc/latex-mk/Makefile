# ex:ts=8
# Ports collection makefile for:	latex-mk
# Date created:			May 22, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	latex-mk
PORTVERSION=	1.3
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A collection of makefile and scripts for LaTeX documents

BUILD_DEPENDS=	latex:${PORTSDIR}/print/teTeX
RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

INFO=		latex-mk

.include <bsd.port.mk>
