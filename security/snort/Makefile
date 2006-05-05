# New ports collection makefile for:	snort
# Date created:		Mon Aug  2 12:04:08 CEST 1999
# Whom:			Dirk Froemberg <dirk@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	snort
PORTVERSION=	2.4.4
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.snort.org/dl/current/

MAINTAINER=	question+fbsdports@closedsrc.org
COMMENT=	Lightweight network intrusion detection system

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre

OPTIONS=	FLEXRESP "Flexible response to events" off \
		MYSQL "Enable MySQL support" off \
		ODBC "Enable ODBC support" off \
		POSTGRESQL "Enable PostgreSQL support" off \
		PRELUDE "Enable Prelude NIDS integration" off

USE_GPG=	yes
SIG_SUFFIX=	.sig
USE_REINPLACE=	yes
USE_RC_SUBR=	snort.sh
SUB_FILES=	pkg-message
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="${LDFLAGS}"
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

CONFIG_DIR?=	${PREFIX}/etc/snort
CONFIG_FILES=	classification.config gen-msg.map generators reference.config \
		sid sid-msg.map snort.conf threshold.conf unicode.map

MAN8=		snort.8
DOCS=		RELEASE.NOTES doc/AUTHORS doc/BUGS doc/CREDITS \
		doc/README* doc/USAGE doc/*.pdf

.include <bsd.port.pre.mk>

.if defined(WITH_FLEXRESP)
BUILD_DEPENDS+=		libnet*<=1.1.0,1:${PORTSDIR}/net/libnet10
CONFIGURE_ARGS+=	--enable-flexresp \
			--with-libnet-includes=${LOCALBASE}/include \
			--with-libnet-libraries=${LOCALBASE}/lib
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=		yes
CONFIGURE_ARGS+=	--with-mysql=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--with-mysql=no
.endif

.if defined(WITH_ODBC)
LIB_DEPENDS+=		odbc.1:${PORTSDIR}/databases/unixODBC
CONFIGURE_ARGS+=	--with-odbc=${LOCALBASE}
LDFLAGS+=		${PTHREAD_LIBS}
.else
CONFIGURE_ARGS+=	--with-odbc=no
.endif

.if defined(WITH_POSTGRESQL)
USE_PGSQL=		yes
CONFIGURE_ARGS+=	--with-postgresql=${LOCALBASE}
.if exists(/usr/lib/libssl.a) && exists(/usr/lib/libcrypto.a)
LDFLAGS+=		-lssl -lcrypto
.endif
.else
CONFIGURE_ARGS+=	--with-postgresql=no
.endif

.if defined(WITH_PRELUDE)
LIB_DEPENDS+=		prelude.[7-?]:${PORTSDIR}/security/libprelude
CONFIGURE_ARGS+=	--enable-prelude
PLIST_SUB+=		PRELUDE=""
.else
CONFIGURE_ARGS+=	--disable-prelude
PLIST_SUB+=		PRELUDE="@comment "
.endif

post-patch:
	${REINPLACE_CMD} "s,/etc/snort.conf,${CONFIG_DIR}/snort.conf," \
		${WRKSRC}/src/snort.c ${WRKSRC}/snort.8

post-install:
	[ -d ${CONFIG_DIR} ] || ${MKDIR} ${CONFIG_DIR}
.for f in ${CONFIG_FILES}
	${INSTALL_DATA} ${WRKSRC}/etc/${f} ${CONFIG_DIR}/${f}-sample
.endfor
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/schemas/create* ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
