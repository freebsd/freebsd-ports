# ex:ts=8
# New ports collection makefile for:	libgmp3
# Date created:			Jan 11, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libgmp
PORTVERSION=	4.0.1
CATEGORIES=	math devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	gmp
DISTNAME=	gmp-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

post-patch:
	@${PERL} -pi -e "s/--tag=CC//g" ${WRKSRC}/mpn/Makefile.in

pre-configure:
	@${LN} -fs ${LOCALBASE}/bin/libtool ${WRKSRC}

.include <bsd.port.mk>
