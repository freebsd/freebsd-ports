# New ports collection makefile for:	kdoc
# Date created:				4 March 2001
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kdoc
PORTVERSION=	2.2.2
CATEGORIES=	textproc kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	Attic/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org

USE_BZIP2=	yes

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_PERL5=	yes

MAN1=		kdoc.1 qt2kdoc.1 makekdedoc.1

pre-configure:
	${PERL} -pi -e "s#share/kdoc#lib/perl5/site_perl/${PERL_VER}#" \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
