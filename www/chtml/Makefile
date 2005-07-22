# New ports collection makefile for:	chtml
# Date created:         1 Aug 2001
# Whom:                 David Bushong <david+ports@bushong.net>
#
# $FreeBSD$
#

PORTNAME=       chtml
PORTVERSION=    0.0
CATEGORIES=     www devel lang
MASTER_SITES=   http://people.delphiforums.com/gjc/
DISTNAME=       chtml
EXTRACT_SUFX=   .tgz

MAINTAINER=     ports@FreeBSD.org
COMMENT=	Chunked HTML templating engine

BUILD_DEPENDS=	${LOCALBASE}/bin/csiod:${PORTSDIR}/lang/siod

USE_PERL5_RUN=	yes
MAKE_ENV=	SITE_PERL=${SITE_PERL}
NO_WRKSUBDIR=	yes
MAKEFILE=	makefile

.include <bsd.port.mk>
