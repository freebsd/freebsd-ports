# ex:ts=8
# New ports collection makefile for:	spar
# Date created:			Jun 1, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	spar
PORTVERSION=	0.5.10
CATEGORIES=	math devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	A modular math parser

LIB_DEPENDS=	gnugetopt:${PORTSDIR}/devel/libgnugetopt

USE_REINPLACE=	yes
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib -lgnugetopt"
INSTALLS_SHLIB=	yes

MAN1=	spar.1

post-patch:
	@${REINPLACE_CMD} -e "s,-ldl,,g" ${WRKSRC}/lib/Makefile.in

.include <bsd.port.mk>
