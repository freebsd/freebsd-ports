# Created by: Fredrik Lindberg <fli@shapeshifter.se>
# $FreeBSD$

PORTNAME=	pam_bsdbioapi
PORTVERSION=	1.5.1
CATEGORIES=	security
MASTER_SITES=	http://www.shapeshifter.se/pub/pam_bsdbioapi/

MAINTAINER= ports@FreeBSD.org
COMMENT=	PAM module for BioAPI

LIB_DEPENDS=	libbioapi100.so:${PORTSDIR}/security/bioapi

USE_LDCONFIG=	yes
SUB_FILES=	pkg-message
MAN8=		pam_bsdbioapi.8
MAN3=		libbirdb.3
MAN1=		bbdm.1

OPTIONS_DEFINE=	FILEDB MYSQL PLAIN
OPTIONS_DEFAULT=	FILEDB PLAIN
FILEDB_DESC=	Filebacked database backend
PLAIN_DESC=	Plain ASCII backend

NO_STAGE=	yes
.include <bsd.port.pre.mk>

PLIST_FILES=	etc/birdb.conf.sample
BACKENDS=
.if ${PORT_OPTIONS:MFILEDB}
BACKENDS+=	filedb
PLIST_FILES+=	share/birdb/birdb_filedb.so
.endif
.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
BACKENDS+=	mysql
PLIST_FILES+=	share/birdb/birdb_mysql.so
.endif
.if ${PORT_OPTIONS:MPLAIN}
BACKENDS+=	plain
PLIST_FILES+=	share/birdb/birdb_plain.so
.endif

CFLAGS+=	-fPIC
MAKE_ENV=	BACKENDS="${BACKENDS}"

post-install:
	${INSTALL} ${WRKSRC}/etc/birdb.conf ${PREFIX}/etc/birdb.conf.sample
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
