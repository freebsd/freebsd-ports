# New ports collection makefile for:	nagios-check_bacula
# Date created: 	10 Juli 2008
# Whom:			Anders Troback
#
# $FreeBSD$
#

PORTNAME=	check_bacula
PORTVERSION=	3.0.0
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/bacula
PKGNAMEPREFIX=	nagios-
DISTNAME=	bacula-${PORTVERSION}

MAINTAINER=	freebsd@troback.com
COMMENT=	Nagios plugin for Bacula

WRKSRC=		${WRKDIR}/bacula-${PORTVERSION}
CONFIGURE_ARGS=	--enable-client-only \
		--disable-build-dird \
		--disable-build-stored \
		--disable-nls
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

post-extract:
	${TAR} xzCf ${WRKSRC}/src ${WRKSRC}/examples/nagios/nagios_plugin_check_bacula.tgz

post-build:
	${MAKE} -C ${WRKSRC}/src/check_bacula

do-install:
	@${MKDIR} ${PREFIX}/libexec/nagios
	${INSTALL_PROGRAM} ${WRKSRC}/src/check_bacula/.libs/check_bacula \
		${PREFIX}/libexec/nagios/
	${INSTALL_PROGRAM} ${WRKSRC}/src/lib/.libs/libbac.so.1 \
		${PREFIX}/lib

.include <bsd.port.post.mk>
