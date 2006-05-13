# New ports collection makefile for:	snort_inline
# Date created:        4 March 2005
# Whom:                nick@rogness.net
#
# $FreeBSD$
#

PORTNAME=	snort_inline
PORTVERSION=	2.3.0
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://freebsd.rogness.net/ports/snort_inline/
DISTNAME=	snort_inline-2.3.0-RC1

MAINTAINER=	nick@rogness.net
COMMENT=	An inline IPS system based on snort using ipfw

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre

WRKSRC=		${WRKDIR}/snort_inline-2.3.0-RC1

USE_GPG=	yes
SIG_SUFFIX=	.asc
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="${LDFLAGS}"
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS+=	--enable-inline --enable-ipfw

BUILD_DEPENDS+=		libnet*<=1.1.0,1:${PORTSDIR}/net/libnet10
CONFIGURE_ARGS+=	--with-libnet-includes=${LOCALBASE}/include \
			--with-libnet-libraries=${LOCALBASE}/lib

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

MAN8=		snort.8
DOCS=		ChangeLog doc/AUTHORS doc/BUGS doc/CREDITS doc/faq* doc/NEWS \
		doc/README* doc/TODO doc/USAGE doc/*.pdf

USE_RC_SUBR=	snort.sh

post-patch:
	${REINPLACE_CMD} "s,%%PREFIX%%,${PREFIX}," ${WRKSRC}/src/snort.c

pre-configure:
	@${ECHO} ""
	@${ECHO} "Set WITH_MYSQL, WITH_ODBC or WITH_POSTGRESQL"
	@${ECHO} "to get additional support."
	@${ECHO} ""

post-install:
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/rules/*.rules ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/etc/classification.config \
		${DATADIR}/classification.config-sample
	[ -f ${DATADIR}/classification.config ] || \
		${CP} ${DATADIR}/classification.config-sample \
		${DATADIR}/classification.config
	${INSTALL_DATA} ${WRKSRC}/etc/reference.config \
		${DATADIR}/reference.config-sample
	[ -f ${DATADIR}/reference.config ] ||  \
		${CP} ${DATADIR}/reference.config-sample ${DATADIR}/reference.config
.for f in snort.conf snort_inline.conf unicode.map threshold.conf
	${INSTALL_DATA} ${WRKSRC}/etc/${f} ${PREFIX}/etc/${f}-sample
	[ -f ${PREFIX}/etc/${f} ] || \
		${INSTALL_DATA} ${WRKSRC}/etc/${f} ${PREFIX}/etc/${f}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
