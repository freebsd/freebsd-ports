# New ports collection makefile for:	snort
# Date created:		Mon Aug  2 12:04:08 CEST 1999
# Whom:			Dirk Froemberg <dirk@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	snort
PORTVERSION=	2.2.0
CATEGORIES=	security
MASTER_SITES=	http://www.snort.org/dl/

MAINTAINER=	sergei@FreeBSD.org
COMMENT=	Lightweight network intrusion detection system

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre

OPTIONS=	FLEXRESP "Flexible response to events" off \
		MYSQL "Enable MySQL support" off \
		ODBC "Enable ODBC support" off \
		POSTGRESQL "Enable PostgreSQL support" off

USE_GPG=	yes
SIG_SUFFIX=	.asc
USE_REINPLACE=	yes
USE_RC_SUBR=	yes
RC_SCRIPTS_SUB=	PREFIX=${PREFIX} RC_SUBR=${RC_SUBR}
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="${LDFLAGS}"
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN8=		snort.8
DOCS=		ChangeLog doc/AUTHORS doc/BUGS doc/CREDITS doc/FAQ doc/NEWS \
		doc/README* doc/TODO doc/USAGE doc/snort_manual.pdf

.include <bsd.port.pre.mk>

.if defined(WITH_FLEXRESP)
BUILD_DEPENDS+=		${LOCALBASE}/lib/libnet.a:${PORTSDIR}/net/libnet
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

post-patch:
	${REINPLACE_CMD} "s,%%PREFIX%%,${PREFIX}," ${WRKSRC}/src/snort.c
	@${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/snort.sh > ${WRKDIR}/snort.sh

post-install:
	${INSTALL_SCRIPT} -m 751 ${WRKDIR}/snort.sh ${PREFIX}/etc/rc.d/snort.sh
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/rules/[^l]*.rules ${DATADIR}
.for f in local.rules
	${INSTALL_DATA} ${WRKSRC}/rules/${f} ${DATADIR}/${f}-sample
	[ -f ${DATADIR}/${f} ] || \
	    ${INSTALL_DATA} ${WRKSRC}/rules/${f} ${DATADIR}/${f}
.endfor
.for f in classification.config reference.config
	${INSTALL_DATA} ${WRKSRC}/etc/${f} ${DATADIR}/${f}-sample
	[ -f ${DATADIR}/${f} ] || \
	    ${INSTALL_DATA} ${WRKSRC}/etc/${f} ${DATADIR}/${f}
.endfor
.for f in snort.conf unicode.map threshold.conf
	${INSTALL_DATA} ${WRKSRC}/etc/${f} ${PREFIX}/etc/${f}-sample
	[ -f ${PREFIX}/etc/${f} ] || \
	    ${INSTALL_DATA} ${WRKSRC}/etc/${f} ${PREFIX}/etc/${f}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
