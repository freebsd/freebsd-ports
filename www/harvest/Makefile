# New ports collection makefile for:	harvest
# Date created:		Fri Mar  1 19:43:52 MET 1996
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	harvest
PORTVERSION=	1.9.3
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

USE_BZIP2=	yes
USE_PERL5=	yes
USE_REINPLACE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL} \
		--prefix=${PREFIX}/${PORTNAME} \
		--without-wish 

STRIP=		# none

post-patch:
	@${GREP} -lR "<malloc.h>" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|<malloc\.h>|<stdlib.h>|g'

post-install:
	@(cd ${PREFIX} && ${GREP} -v "@" ${PLIST} | \
		${XARGS} ${STRIP_CMD} 2> /dev/null || ${TRUE})

.include <bsd.port.mk>
