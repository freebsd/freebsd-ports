# New ports collection makefile for:	harvest
# Date created:		Fri Mar  1 19:43:52 MET 1996
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	harvest
PORTVERSION=	1.9.14
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Collect information from all over the Internet

USE_BZIP2=		yes
USE_PERL5=		yes
USE_AUTOTOOLS=	libtool:22
LIBTOOLFILES=	configure src/gatherer/curl/configure
USE_LDCONFIG=	yes
NO_MTREE=		yes
CONFIGURE_ARGS?=	--prefix=${PREFIX}/${PORTNAME} --without-wish

STRIP=		# none

.include <bsd.port.pre.mk>

PREFIX:=	${PREFIX}/${PORTNAME}

post-patch:
	@${GREP} -lR "<malloc.h>" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|<malloc\.h>|<stdlib.h>|g'

port-configure:
	@${REINPLACE_CMD} "s!^INSTALL =\(.*\)!INSTALL = ${INSTALL}!" \
			${WRKSRC}/src/gatherer/curl/lib/Makefile

post-install:
	@(cd ${PREFIX} && ${GREP} -v "@" ${PLIST} | \
		${XARGS} ${STRIP_CMD} 2> /dev/null || ${TRUE})

.include <bsd.port.post.mk>
