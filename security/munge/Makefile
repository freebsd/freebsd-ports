# Created by: Muhammad Moinur Rahman <5u623l20@gmail.com>
# $FreeBSD$

PORTNAME=	munge
PORTVERSION=	0.5.11
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Authentication service for creating and validating credentials

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	dual

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var
USES=		libtool pathfix perl5 tar:bzip2
USE_LDCONFIG=	yes
USE_RC_SUBR=	munged

post-install:
	${RM} -r ${STAGEDIR}${PREFIX}/etc/default
	${RM} -r ${STAGEDIR}${PREFIX}/etc/init.d
	${RM} -r ${STAGEDIR}${ETCDIR}

.include <bsd.port.mk>
