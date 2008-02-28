# ex:ts=8
# Ports collection makefile for:	libEtPan!
# Date created:			Jun 27, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libetpan
PORTVERSION=	0.54
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	c0rn@o2.pl
COMMENT=	A mail library

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl \
		expat:${PORTSDIR}/textproc/expat2 \
		sasl2.2:${PORTSDIR}/security/cyrus-sasl2

USE_ICONV=	yes
USE_AUTOTOOLS=	libtool:15 autoconf:261
USE_LDCONFIG=	yes
USE_GMAKE=	yes

CFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

CONFIGURE_ENV=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

.if defined(WITH_GNUTLS)
LIB_DEPENDS+=	gnutls.13:${PORTSDIR}/security/gnutls
CONFIGURE_ARGS+=	--without-openssl --with-gnutls
.else
USE_OPENSSL=	yes
CONFIGURE_ARGS+=	--without-gnutls
.endif

post-install:
	@${FIND} ${PREFIX}/include/libetpan* ! -type d | ${SED} \
		's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${PREFIX}/include/libetpan -type d | ${SORT} | ${SED} \
		's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}

.include <bsd.port.mk>
