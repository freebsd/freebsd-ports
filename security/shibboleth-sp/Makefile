# New ports collection makefile for:	security/shibboleth-sp
# Date created:		2007-07-17
# Whom:			Janos Mohacsi <janos.mohacsi@bsd.hu>
#
# $FreeBSD$
#

PORTNAME=	shibboleth-sp
PORTVERSION=	1.3f
CATEGORIES=	security www
MASTER_SITES=	http://shibboleth.internet2.edu/downloads/

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	C++ Shibboleth Service Provider (Internet2) for Apache

LIB_DEPENDS=	saml.5:${PORTSDIR}/security/opensaml

BROKEN=		does not build

OPTIONS=	APACHE22 "Use Apache version 2.2 instead of version 2.0"  on

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_RC_SUBR=	shibboleth-sp
WRKSRC=		${WRKDIR}/shibboleth-1.3

.include <bsd.port.pre.mk>

.if defined(WITH_APACHE22)
USE_APACHE=	22
CONFIGURE_ARGS=	--enable-apache-22 --with-apxs22=${APXS}
.else
USE_APACHE=	20
CONFIGURE_ARGS=	--enable-apache-20 --with-apxs2=${APXS}
.endif
CONFIGURE_ARGS+=	--localstatedir=/var

post-patch:
	@${REINPLACE_CMD} -e 's|/run|/run/shibboleth|' ${WRKSRC}/configs/Makefile.in
	@${REINPLACE_CMD} -e 's|/doc/|/share/doc/|' ${WRKSRC}/doc/Makefile.in

.if ${OSVERSION} >= 700042
BROKEN=		Does not compile with GCC 4.2
.endif
.if ${ARCH} == "amd64" || ${ARCH} == "sparc64"
BROKEN=		Does not compile; author is investigating
.endif

.include <bsd.port.post.mk>
