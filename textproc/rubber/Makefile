# ex:ts=8
# Ports collection Makefile for:	rubber
# Date created:			Mar 27, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	rubber
PORTVERSION=	0.99.8
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A wrapper for LaTeX and friends

RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX

USE_PYTHON=	yes
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --moddir=${PYTHON_SITELIBDIR}

MANLANG=	"" fr
MAN1=		rubber.1 rubber-info.1
INFO=		rubber

pre-install:
	${INSTALL_DATA} ${WRKSRC}/doc/rubber.info ${PREFIX}/info
	@install-info ${PREFIX}/info/rubber.info ${PREFIX}/info/dir

.include <bsd.port.mk>
