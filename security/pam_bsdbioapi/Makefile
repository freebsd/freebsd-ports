# Ports collection makefile for:	pam_bsdbioapi
# Date created:				13 January 2006
# Whom:					Fredrik Lindberg <fli@shapeshifter.se>
#
# $FreeBSD$
#

PORTNAME=	pam_bsdbioapi
PORTVERSION=	1.5
CATEGORIES=	security
MASTER_SITES=	http://shapeshifter.se/pub/pam_bsdbioapi/

MAINTAINER=	fli@shapeshifter.se
COMMENT=	PAM module for BioAPI

LIB_DEPENDS=	bioapi100.0:${PORTSDIR}/security/bioapi

INSTALLS_SHLIB=	yes
SUB_FILES=	pkg-message
MAN8=		pam_bsdbioapi.8
MAN3=		libbirdb.3
MAN1=		bbdm.1

OPTIONS=	FILEDB "Filebacked database backend" on \
		MYSQL  "MySQL backend" off \
		PLAIN  "Plain ASCII backend" on

.include <bsd.port.pre.mk>

PLIST_FILES=	etc/birdb.conf.sample
BACKENDS=
.if defined(WITH_FILEDB)
BACKENDS+=	filedb
PLIST_FILES+=	share/birdb/birdb_filedb.so
.endif
.if defined(WITH_MYSQL)
USE_MYSQL=	yes
BACKENDS+=	mysql
PLIST_FILES+=	share/birdb/birdb_mysql.so
.endif
.if defined(WITH_PLAIN)
BACKENDS+=	plain
PLIST_FILES+=	share/birdb/birdb_plain.so
.endif

CFLAGS+=	-fPIC
MAKE_ENV=	BACKENDS="${BACKENDS}"

post-install:
	${INSTALL} ${WRKSRC}/etc/birdb.conf ${PREFIX}/etc/birdb.conf.sample
	@${CAT} ${PKGMESSAGE}

.if ${OSVERSION} < 500000
IGNORE=		needs at least FreeBSD 5.0-RELEASE
.endif

.include <bsd.port.post.mk>
