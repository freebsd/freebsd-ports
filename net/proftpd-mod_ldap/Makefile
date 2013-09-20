# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mod_ldap
CATEGORIES=	net ftp
PKGNAMEPREFIX=	proftpd-

MAINTAINER=	mm@FreeBSD.org
COMMENT=	LDAP and quotatab_ldap ProFTPD modules

LICENSE=	GPLv2

DESCR=		${.CURDIR}/pkg-descr

LATEST_LINK=	${PKGNAMEPREFIX}-${PORTNAME}
MASTERDIR=	${.CURDIR}/../../ftp/proftpd

USE_OPENLDAP=	yes
USE_OPENSSL=	yes

INCLUDEDIRS=	${LOCALBASE}/include
LIBDIRS=	${LOCALBASE}/lib

_BUILDING_PROFTPD_MODULE=	${PORTNAME} \
				mod_quotatab_ldap

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile"
