# Created by: mgrooms@shrew.net
# $FreeBSD$

PORTNAME=	ike
PORTVERSION=	2.2.1
PORTREVISION=	3
CATEGORIES=	security net
MASTER_SITES=	https://www.shrew.net/download/ike/
DISTNAME=	${PORTNAME}-${PORTVERSION}-release

MAINTAINER=	mgrooms@shrew.net
COMMENT=	Shrew Soft IKE daemon and client tools

ONLY_FOR_ARCHS=	i386 amd64

USE_RC_SUBR=	iked
USES=		bison cmake:insource libedit localbase:ldflags tar:tbz2 ssl
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

CMAKE_ARGS=	-DETCDIR:PATH="${PREFIX}/etc" \
		-DBINDIR:PATH="${PREFIX}/bin" \
		-DSBINDIR:PATH="${PREFIX}/sbin" \
		-DLIBDIR:PATH="${PREFIX}/lib" \
		-DMANDIR:PATH="${PREFIX}/man"

OPTIONS_DEFINE=	NATT LDAP DEBUG
OPTIONS_SUB=	yes

NATT_DESC=	Enable NAT-Traversal
LDAP_DESC=	Enable LDAP XAuth daemon support

DEBUG_CMAKE_ON=	-DDEBUG=YES

LDAP_USE=	OPENLDAP=yes
LDAP_CMAKE_ON=	-DLDAP=YES
NATT_CMAKE_ON=	-DNATT=YES

post-install:
	@if ! ${SYSCTL} -a | ${GREP} -q ipsec; then \
	${ECHO_MSG} "===> -------------------------------------------------------------------------"; \
	${ECHO_MSG} "===> WARNING: You need IPsec support in your kernel, please see:"; \
	${ECHO_MSG} "===>   http://www.freebsd.org/doc/en/books/handbook/ipsec.html"; \
	${ECHO_MSG} "===> -------------------------------------------------------------------------"; \
	fi ;

post-install-NATT-on:
	@${ECHO_MSG} "===> -------------------------------------------------------------------------"
	@${ECHO_MSG} "===> WARNING: To use NAT Traversal ( NAT-T ) support, please be sure to"
	@${ECHO_MSG} "===> include the following line in your kernel config file."
	@${ECHO_MSG} "===>   options IPSEC_NAT_T"
	@${ECHO_MSG} "===> -------------------------------------------------------------------------"

.include <bsd.port.mk>

PATCH_ARGS+=	-l
