# New ports collection makefile for:	open-axiom
# Date created:		12 October 2008
# Whom:			stephen@math.missouri.edu
#
# $FreeBSD$
#

PORTNAME=	open-axiom
PORTVERSION=	1.3.0
CATEGORIES=	math
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	stephen@missouri.edu
COMMENT=	A computer algebra system

BUILD_DEPENDS=	sbcl:${PORTSDIR}/lang/sbcl \
		noweb:${PORTSDIR}/devel/noweb

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-lisp=sbcl
USE_GMAKE=	yes
USE_XORG=	x11 ice sm xpm
USE_ICONV=	yes
USE_GETTEXT=	yes
MAKE_JOBS_UNSAFE=yes

PLIST_SUB=	AXIOM_VER=${PORTVERSION} GNU_HOST=${CONFIGURE_TARGET}

.include <bsd.port.mk>
