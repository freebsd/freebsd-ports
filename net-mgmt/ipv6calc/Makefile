# New ports collection makefile for:	ipv6calc
# Date created:				30 January 2002
# Whom:				Edwin Groothuis <edwin@mavetju.org>
#
# $FreeBSD$
#

PORTNAME=	ipv6calc
PORTVERSION=	0.34
CATEGORIES=	net ipv6
MASTER_SITES=	ftp://ftp.bieringer.de/pub/linux/IPv6/ipv6calc/

MAINTAINER=	edwin@mavetju.org

LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext \
		gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes

post-extract:
.for junk in config.h config.log Makefile config.status ipv6calc.h \
	config.cache
	@${RM} ${WRKSRC}/${junk}
.endfor

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/ipv6calc ${PREFIX}/bin

.include <bsd.port.mk>
