# New ports collection makefile for:	libhome
# Date created:				Fri Aug 14 2003
# Whom:					Xavier Beaudouin <kiwi@oav.net>
#
# $FreeBSD$
#

PORTNAME=	lmtpd
PORTVERSION=	0.9.16
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pll

MAINTAINER=	kiwi@oav.net
COMMENT=	LMTP server compliant with RFC 2033 and Maildir++

LIB_DEPENDS=	iconv:${PORTSDIR}/converters/libiconv
BUILD_DEPENDS=	${LOCALBASE}/lib/libhome.a:${PORTSDIR}/misc/libhome

OPTIONS=	PCRE "Support for PCRE" on

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/mysql/libmysqlclient.so)
WITH_MYSQL=	yes
OPTIONS+=	MYSQL "Support for MySQL Queries and Logs" on
.else
OPTIONS+=	MYSQL "Support for MySQL Queries and Logs" off
.endif

.if exists(${LOCALBASE}/lib/libdb3.so)
WITH_DB3=	yes
OPTIONS+=	DB3 "Support for DB3" on
.else
OPTIONS+=	DB3 "Support for DB3" off
.endif

.if exists(${LOCALBASE}/lib/libdb4.so)
WITH_DB4=	yes
OPTIONS+=	DB4 "Support for DB4" on
.else
OPTIONS+=	DB4 "Support for DB4" off
.endif

.if defined(WITH_DB3) && defined(WITH_DB4)
.error You cannot use DB3 and DB4 in the same time.
.endif

.if defined(WITH_PCRE)
LIB_DEPENDS+=	pcre:${PORTSDIR}/devel/pcre
CONFIGURE_ARGS+=	--with-pcre
.else
CONFIGURE_ARGS+=	--without-pcre
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
CONFIGURE_ARGS+=	--with-mysql=${LOCALBASE}/include/mysql --with-mysqllog
.else
CONFIGURE_ARGS+=	--without-mysql --without-mysqllog
.endif

.if defined(WITH_DB3)
LIB_DEPENDS+=	db3.3:${PORTSDIR}/databases/db3
CONFIGURE_ARGS+=	--with-db3=${LOCALBASE}/include/db3 --without-db4
.else
CONFIGURE_ARGS+=	--without-db3
.endif

.if defined(WITH_DB4)
LIB_DEPENDS+=	db4:${PORTSDIR}/databases/db4
CONFIGURE_ARGS+=	--with-db4=${LOCALBASE}/include/db4 --without-db3
.else
CONFIGURE_ARGS+=	--without-db4
.endif

GNU_CONFIGURE=	YES
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include"
CONFIGURE_ARGS+=	--without-perl
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN8=		lmtpd.8
DOCS=		NEWS README TODO

post-install:
	${INSTALL_DATA} ${WRKSRC}/samples/lmtpd.conf \
		${PREFIX}/etc/lmtpd.conf.dist
	${INSTALL_SCRIPT} ${WRKSRC}/lmtpdlogsum/lmtpdlogsum.pl \
		${PREFIX}/bin/lmtpdlogsum
	@${MKDIR} ${EXAMPLESDIR}/msg
	${INSTALL_DATA} ${WRKSRC}/sql/* ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/txt/* ${EXAMPLESDIR}/msg
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
