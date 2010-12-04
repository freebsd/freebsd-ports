# New ports collection makefile for:	security/shibboleth2-sp
# Date created:		17 Sept2008
# Whom:			Janos Mohacsi <janos.mohacsi@bsd.hu>
#
# $FreeBSD$
#

PORTNAME=	shibboleth-sp
PORTVERSION=	2.3.1
PORTREVISION=	1
CATEGORIES=	security www
MASTER_SITES=	http://shibboleth.internet2.edu/downloads/shibboleth/cppsp/${PORTVERSION}/

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	C++ Shibboleth Service Provider (Internet2) for Apache

LIB_DEPENDS=	saml.6:${PORTSDIR}/security/opensaml2

OPTIONS=	APACHE22 "Use Apache version 2.2 instead of version 2.0" on

MAKE_JOBS_SAFE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_RC_SUBR=	shibboleth-sp
USE_AUTOTOOLS=	autoconf automake:env libtool:env
WRKSRC=		${WRKDIR}/shibboleth-${PORTVERSION}

LATEST_LINK=	shibboleth2-sp

.include <bsd.port.pre.mk>

.if defined(WITH_APACHE22)
USE_APACHE=	22
CONFIGURE_ARGS=	--enable-apache-22 --with-apxs22=${APXS}
PLIST_SUB+=	WITH_APACHE_22=""
PLIST_SUB+=	WITH_APACHE_20="@comment "
.else
USE_APACHE=	20
CONFIGURE_ARGS=	--enable-apache-20 --with-apxs2=${APXS} --with-apr=${PREFIX}/lib/apache2/apr-config --with-apu=${PREFIX}/lib/apache2/apu-config
PLIST_SUB+=	WITH_APACHE_22="@comment "
PLIST_SUB+=	WITH_APACHE_20=""
.endif
CONFIGURE_ARGS+=	--localstatedir=/var --with-log4shib=${LOCALBASE}
CONFIGURE_ARGS+=	--with-openssl=${OPENSSLBASE} --with-xmltooling=${LOCALBASE}
CONFIGURE_ARGS+=	--disable-doxygen-doc

pre-configure:
	@${REINPLACE_CMD} -e 's|/run|/run/shibboleth|' ${WRKSRC}/configs/Makefile.in
	@${REINPLACE_CMD} -e 's|/doc/@PACKAGE@-@PACKAGE_VERSION@|/doc/@PACKAGE@|' \
		${WRKSRC}/configs/Makefile.am ${WRKSRC}/configs/Makefile.in \
		${WRKSRC}/doc/Makefile.am ${WRKSRC}/doc/Makefile.in
	${RM} ${WRKSRC}/aclocal.m4
	@cd ${WRKSRC} && ${AUTORECONF} -fvi

.include <bsd.port.post.mk>
