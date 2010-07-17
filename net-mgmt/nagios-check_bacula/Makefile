# New ports collection makefile for:	nagios-check_bacula
# Date created: 	10 Juli 2008
# Whom:			Anders Troback
#
# $FreeBSD$
#

PORTNAME=	bacula
PKGNAMEPREFIX=  nagios-check_
CATEGORIES=	net-mgmt
UNIQUENAME=	${PKGNAMEPREFIX}${PORTNAME}

MAINTAINER=	freebsd@troback.com
COMMENT=	Nagios plugin for Bacula

WITH_NAGIOS_CHECK_ONLY=	yes
MASTERDIR=	${.CURDIR}/../../sysutils/bacula-server
PLIST=		${.CURDIR}/pkg-plist

CONFIGURE_ARGS=	--enable-client-only \
		--disable-build-dird \
		--disable-build-stored \
		--disable-nls \
		--disable-xatt

.include "${MASTERDIR}/Makefile"

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libbac.so.${PORTVERSION:R:R})
LIB_DEPENDS+=	bac.${PORTVERSION:R:R}:${PORTSDIR}/sysutils/bacula-client
WITHOUT_LIBBAC=	YES
PLIST_SUB+=	INDEP="@comment "
.else
PLIST_SUB+=	INDEP=""
.endif

pre-everything::
	@${ECHO_MSG} "===> Building nagios check only."

post-build:
	${MAKE} -C ${WRKSRC}/examples/nagios/check_bacula

do-install:
	@${MKDIR} ${PREFIX}/libexec/nagios
	${INSTALL_PROGRAM} ${WRKSRC}/examples/nagios/check_bacula/.libs/check_bacula \
	    ${PREFIX}/libexec/nagios
.if !defined(WITHOUT_LIBBAC)
	@${ECHO_MSG} "===> Installing libbac.so.${PORTVERSION:R:R} "
	${INSTALL_PROGRAM} ${WRKSRC}/src/lib/.libs/libbac.so.${PORTVERSION:R:R} \
	    ${PREFIX}/lib
.endif

.include <bsd.port.post.mk>
