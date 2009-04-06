# New ports collection makefile for:	fricas
# Date created:		11 November 2008
# Whom:			stephen@math.missouri.edu
#
# $FreeBSD$
#

PORTNAME=	fricas
PORTVERSION=	1.0.5
CATEGORIES=	math
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}-full

MAINTAINER=	stephen@missouri.edu
COMMENT=	A computer algebra system, forked from axiom

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
STRIP=		#nothing, these binaries fail if stripped

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_SUB=	GNU_HOST=${CONFIGURE_TARGET}

.include <bsd.port.mk>
