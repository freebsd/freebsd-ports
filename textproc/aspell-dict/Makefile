# New ports collection makefile for:    en-aspell-dict
# Date created:                         25 August 2002
# Whom:                                 Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=	aspell-dict
PORTVERSION=	0.50
CATEGORIES=	textproc
MASTER_SITES=	http://savannah.gnu.org/download/${PORTRNAME}/rel/	\
		${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTRNAME}
PKGNAMEPREFIX=	en-
DISTNAME=	${PORTRNAME}-${PKGNAMEPREFIX}${PORTVERSION}-${DISTREVISION}

MAINTAINER=	thierry@pompo.net

BUILD_DEPENDS=	${LOCALBASE}/bin/aspell:${PORTSDIR}/textproc/aspell
RUN_DEPENDS=	${LOCALBASE}/bin/aspell:${PORTSDIR}/textproc/aspell

USE_BZIP2=	yes
HAS_CONFIGURE=	yes
USE_GMAKE=	yes

CONFIGURE_ENV=	ASPELL="${LOCALBASE}/bin/aspell"	\
		WORD_LIST_COMPRESS="${LOCALBASE}/bin/word-list-compress"

PORTRNAME=	${PORTNAME:S/-dict//}
DISTREVISION=	2

.include <bsd.port.mk>
