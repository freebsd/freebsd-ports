PORTNAME=	mod_ldap
PORTREVISION=	4
CATEGORIES=	net ftp
PKGNAMEPREFIX=	proftpd-

MAINTAINER=	mm@FreeBSD.org
COMMENT=	LDAP and quotatab_ldap ProFTPD modules

LICENSE=	GPLv2

DESCR=		${.CURDIR}/pkg-descr

MASTERDIR=	${.CURDIR}/../../ftp/proftpd

USE_OPENLDAP=	yes
USES=		cpe ssl

INCLUDEDIRS=	${LOCALBASE}/include
LIBDIRS=	${LOCALBASE}/lib

_BUILDING_PROFTPD_MODULE=	${PORTNAME} \
				mod_quotatab_ldap

.include "${MASTERDIR}/Makefile"
