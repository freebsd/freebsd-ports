PORTNAME=	fts-flatcurve
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.5
PORTREVISION=	2
CATEGORIES=	mail
PKGNAMEPREFIX=	dovecot-

MAINTAINER=	martin@waschbuesch.de
COMMENT=	Dovecot FTS plugin based on Xapian
WWW=		https://github.com/slusarz/dovecot-fts-flatcurve

LICENSE=	LGPL21

FLAVORS=        default mysql pgsql
FLAVOR?=        ${FLAVORS[1]}
mysql_PKGNAMESUFFIX=    -mysql
pgsql_PKGNAMESUFFIX=    -pgsql
BUILD_DEPENDS=  dovecot>=2.3.17:mail/dovecot@default
RUN_DEPENDS=    dovecot>=2.3.17:mail/dovecot@default
.if ${FLAVOR:U} == mysql
BUILD_DEPENDS=  dovecot-mysql>=2.3.17:mail/dovecot@mysql
RUN_DEPENDS=    dovecot-mysql>=2.3.17:mail/dovecot@mysql
.endif
.if ${FLAVOR:U} == pgsql
BUILD_DEPENDS=  dovecot-pgsql>=2.3.17:mail/dovecot@pgsql
RUN_DEPENDS=    dovecot-pgsql>=2.3.17:mail/dovecot@pgsql
.endif

LIB_DEPENDS=	libicuuc.so:devel/icu \
		libxapian.so:databases/xapian-core

USES=		autoreconf libtool pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	slusarz
GH_PROJECT=	dovecot-fts-flatcurve
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

PLIST_FILES=	include/dovecot-fts-flatcurve/fts-flatcurve-config.h \
		lib/dovecot/doveadm/lib21_doveadm_fts_flatcurve_plugin.a \
		lib/dovecot/doveadm/lib21_doveadm_fts_flatcurve_plugin.so \
		lib/dovecot/lib21_fts_flatcurve_plugin.a \
		lib/dovecot/lib21_fts_flatcurve_plugin.so

post-install:
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/dovecot/lib21_fts_flatcurve_plugin.so
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/dovecot/doveadm/lib21_doveadm_fts_flatcurve_plugin.so

.include <bsd.port.mk>
