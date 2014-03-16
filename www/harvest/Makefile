# Created by: Andreas Klemm <andreas@klemm.gtn.com>
# $FreeBSD$

PORTNAME=	harvest
PORTVERSION=	1.9.14
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20devel/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Collect information from all over the Internet

USES=		tar:bzip2 perl5
USE_AUTOTOOLS=	libtool
LIBTOOLFILES=	configure src/gatherer/curl/configure
USE_LDCONFIG=	yes
NO_MTREE=	yes
CONFIGURE_ARGS?=	--prefix=${PREFIX}/${PORTNAME} --without-wish
MAKE_JOBS_UNSAFE=yes

STRIP=		# none

NO_STAGE=	yes
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
