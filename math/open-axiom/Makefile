# New ports collection makefile for:	open-axiom
# Date created:		12 October 2008
# Whom:			stephen@math.missouri.edu
#
# $FreeBSD$
#

PORTNAME=	open-axiom
PORTVERSION=	1.2.1
CATEGORIES=	math
MASTER_SITES=	SF

MAINTAINER=	stephen@missouri.edu
COMMENT=	A computer algebra system

BUILD_DEPENDS=	clisp:${PORTSDIR}/lang/clisp \
		noweb:${PORTSDIR}/devel/noweb
LIB_DEPENDS=	readline:${PORTSDIR}/devel/readline \
		sigsegv:${PORTSDIR}/devel/libsigsegv

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-lisp=clisp
USE_GMAKE=	yes
USE_XORG=	x11 ice sm xpm
USE_ICONV=	yes
USE_GETTEXT=	yes

PLIST_SUB=	AXIOM_VER=${PORTVERSION} GNU_HOST=${CONFIGURE_TARGET}

.include <bsd.port.mk>
