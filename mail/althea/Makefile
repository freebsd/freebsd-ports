# New ports collection makefile for:	Althea
# Date created:		Feb 26, 2001
# Whom:			Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	althea
PORTVERSION=	0.3.4
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@freebsd.org

USE_GTK=	yes
MAKEFILE=	${FILESDIR}/Makefile.bsd
MAKE_ARGS+=	-j 2
MAKE_ENV+=	INSTALL_DATA="${INSTALL_DATA}" MKDIR="${MKDIR}"

post-patch:
	${PERL} -pi -e "s%/etc%${LOCALBASE}/etc%g" \
		${WRKSRC}/Documentation/help.html \
		${WRKSRC}/load_config.h

.include <bsd.port.mk>
