# ex:ts=8
# Ports collection makefile for:	libEtPan!
# Date created:			Jun 27, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libetpan
PORTVERSION=	0.49
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	c0rn@o2.pl
COMMENT=	A mail library

USE_ICONV=	yes
USE_AUTOTOOLS=	libtool:15 autoconf:259
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
USE_LDCONFIG=	yes
USE_GMAKE=	YES

CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.if defined(WITH_GNUTLS)
LIB_DEPENDS+=	gnutls.15:${PORTSDIR}/security/gnutls
CONFIGURE_ARGS+=	--with-gnutls
.else
USE_OPENSSL=	yes
CONFIGURE_ARGS+=	--without-gnutls
.endif

.if defined(WITH_SASL)
LIB_DEPENDS+=	sasl2.2:${PORTSDIR}/security/cyrus-sasl2
.else
CONFIGURE_ARGS+=	--without-sasl
.endif

post-install:
	@${FIND} ${PREFIX}/include/libetpan* ! -type d | ${SED} \
		's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${PREFIX}/include/libetpan -type d | ${SORT} | ${SED} \
		's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}

.include <bsd.port.mk>
