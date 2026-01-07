PORTNAME=	mod_ldap
PORTREVISION=	6
CATEGORIES=	net ftp
PKGNAMEPREFIX=	proftpd-

MAINTAINER=	mm@FreeBSD.org
COMMENT=	LDAP and quotatab_ldap ProFTPD modules
WWW=		http://www.proftpd.org/docs/contrib/mod_ldap.html

LICENSE=	GPLv2

DESCR=		${.CURDIR}/pkg-descr

MASTERDIR=	${.CURDIR}/../../ftp/proftpd

USES=		cpe ldap ssl

INCLUDEDIRS=	${LOCALBASE}/include
LIBDIRS=	${LOCALBASE}/lib

_BUILDING_PROFTPD_MODULE=	${PORTNAME} \
				mod_quotatab_ldap

.include "${MASTERDIR}/Makefile"
