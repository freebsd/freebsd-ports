PORTNAME=	fts-flatcurve
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.3
PORTREVISION=	1
CATEGORIES=	mail
PKGNAMEPREFIX=	dovecot-

MAINTAINER=	martin@waschbuesch.de
COMMENT=	Dovecot FTS plugin based on Xapian
WWW=		https://github.com/slusarz/dovecot-fts-flatcurve

LICENSE=	LGPL21

BUILD_DEPENDS=	dovecot>=2.3.17:mail/dovecot
LIB_DEPENDS=	libicuuc.so:devel/icu \
		libxapian.so:databases/xapian-core
RUN_DEPENDS=	dovecot>=2.3.17:mail/dovecot

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
