# Created by: Muhammad Moinur Rahman <5u623l20@gmail.com>
# $FreeBSD$

PORTNAME=	munge
PORTVERSION=	0.5.11
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Authentication service for creating and validating credentials

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	dual

BROKEN=		Unfetchable (google code has gone away)

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-openssl-prefix=${OPENSSLBASE}
USES=		libtool pathfix perl5 ssl tar:bzip2
USE_LDCONFIG=	yes
USE_RC_SUBR=	munged
INSTALL_TARGET=	install-strip

post-install:
	${RM} -r ${STAGEDIR}${PREFIX}/etc/default
	${RM} -r ${STAGEDIR}${PREFIX}/etc/init.d
	${RM} -r ${STAGEDIR}${ETCDIR}

.include <bsd.port.mk>
