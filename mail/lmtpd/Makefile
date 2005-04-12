# New ports collection makefile for:	libhome
# Date created:				Fri Aug 14 2003
# Whom:					Xavier Beaudouin <kiwi@oav.net>
#
# $FreeBSD$
#

PORTNAME=	lmtpd
PORTVERSION=	0.9.19
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.oav.net/pll/ ${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pll

MAINTAINER=	kiwi@oav.net
COMMENT=	LMTP server compliant with RFC 2033 and Maildir++

LIB_DEPENDS=	home.1:${PORTSDIR}/misc/libhome

USE_ICONV=	yes

OPTIONS=	PCRE "Support for PCRE" on
OPTIONS+=	MYSQL "Support for MySQL Queries and Logs" on
OPTIONS+=	DB3 "Support for DB3" on
OPTIONS+=	DB4 "Support for DB4" off
OPTIONS+=	TRE "Support for TRE regexp (Approx regexp)" on

.include <bsd.port.pre.mk>

.if defined(WITH_DB3) && defined(WITH_DB4)
.error You cannot use DB3 and DB4 in the same time.
.endif

.if defined(WITH_PCRE)
LIB_DEPENDS+=	pcre:${PORTSDIR}/devel/pcre
CONFIGURE_ARGS+=	--with-pcre
.else
CONFIGURE_ARGS+=	--without-pcre
.endif

.if defined(WITH_TRE)
LIB_DEPENDS+=	tre:${PORTSDIR}/textproc/libtre/
CONFIGURE_ARGS+=	--with-tre
.else
CONFIGURE_ARGS+=	--without-tre
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
