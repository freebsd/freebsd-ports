# New ports collection makefile for:	aspell
# Date created:				7 December 1998
# Whom:					Josh Gilliam <josh@quick.net>
#
# $FreeBSD$
#

PORTNAME=	aspell
PORTVERSION=	0.33.7.1
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/^0//}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	pspell.4:${PORTSDIR}/textproc/pspell

USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--enable-dict-dir=${DATADIR} \
		--enable-doc-dir=${DOCSDIR}
USE_GMAKE=	yes
MAKE_ARGS=	NOPORTDOCS=${NOPORTDOCS}
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
