# New ports collection makefile for:	pspell
# Date created:				13th June 2000
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pspell
PORTVERSION=	0.12
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/^0//}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	ltdl.1:${PORTSDIR}/devel/libtool

USE_NEWGCC=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
LIBTOOLFILES=	configure modules/configure libltdl/configure
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--enable-doc-dir=${PREFIX}/share/doc/pspell
MAKE_ARGS=	NOPORTDOCS=${NOPORTDOCS}
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
