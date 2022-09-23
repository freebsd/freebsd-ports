PKGNAMESUFFIX=	-web

COMMENT=	Baculum Web

LICENSE=	AGPLv3

RUN_DEPENDS=	baculum-common>0:www/baculum-common

PLIST=		${.CURDIR}/pkg-plist

USE_PHP=	curl ldap

OPTIONS_DEFINE=	LCUSER
LCUSER_EXTRA_PATCHES=	${PATCHDIR}/extra-patch-baculum_protected_Web_Class_WebUserManager.php
LCUSER_DESC=	Force username to lowercase. (Useful for kerberos)

MASTERDIR=	${.CURDIR}/../baculum-common

.include "${MASTERDIR}/Makefile"
