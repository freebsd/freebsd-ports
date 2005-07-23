# New ports collection makefile for:	mail/dcc-dccd
# Date created:		Wed Oct 9 19:30:00 WST 2002
# Whom:			Dean Hollister <dean@odyssey.apana.org.au>
#
# $FreeBSD$
#

PORTNAME=	dcc-dccd
PORTVERSION=	1.3.5
CATEGORIES=	mail
MASTER_SITES=	http://www.rhyolite.com/anti-spam/dcc/source/ \
		http://www.wa.apana.org.au/~dean/sources/ \
		ftp://ftp.wa.apana.org.au/pub/unix/packages/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	dean@odyssey.apana.org.au
COMMENT=	Distributed Checksum Clearinghouse procmail, sendmail support

BROKEN=		Incomplete pkg-plist
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=2005-09-22

USE_REINPLACE=	yes
HAS_CONFIGURE=	yes
MANCOMPRESSED=	yes
MAN8=		cdcc.8 dbclean.8 dblist.8 dcc.8 dccd.8 dccifd.8 dccm.8 \
		dccproc.8 dccsight.8

PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall

#
# User for dcc files and SUID binaries
#
DCCUSER?=	dcc
DCCUID?=	112
DCCGROUP?=	dcc
DCCGID?=	112

# if no preference was set, check for an up to date base version
# but give an installed port preference over it.

HOMEDIR=	${PREFIX}/dcc
CONFIGURE_ARGS=	--homedir=${HOMEDIR}

.include <bsd.port.pre.mk>

.if !defined(WITH_SENDMAIL_BASE) && !defined(WITH_SENDMAIL_PORT) && !exists(${LOCALBASE}/lib/libmilter.a)
WITH_SENDMAIL_BASE=yes
.endif

.if defined(WITH_SENDMAIL_BASE)
.if exists(/usr/lib/libmilter.a)
MILTERBASE=	/usr
WITH_SENDMAIL=	yes
.else
.if !defined(WITHOUT_SENDMAIL)
BROKEN=		"Base system sendmail not found or too old, rebuild with WITH_SENDMAIL_PORT=yes or WITHOUT_SENDMAIL=yes"
.endif
.endif
.else
BUILD_DEPENDS+=	${LOCALBASE}/lib/libmilter.a:${PORTSDIR}/mail/sendmail
MILTERBASE?=	${LOCALBASE}
WITH_SENDMAIL=	yes
.endif

.if !defined(WITHOUT_SENDMAIL) && defined(WITH_SENDMAIL)
MILTERINC=	${MILTERBASE}/include
MILTERLIB=	${MILTERBASE}/lib

CPPFLAGS+=	-I${MILTERINC}
LDFLAGS+=	-L${MILTERLIB}

CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS+=	--with-sendmail=${MILTERBASE}
PLIST_SUB+=	WITH_SENDMAIL=""
.else
CONFIGURE_ARGS+=	--disable-dccm
PLIST_SUB+=	WITH_SENDMAIL="@comment "
.endif

.if defined(WITHOUT_DCCIFD)
CONFIGURE_ARGS+=	--disable-dccifd
PLIST_SUB+=	WITH_DCCIFD="@comment "
.else
PLIST_SUB+=	WITH_DCCIFD=""
.endif

CONFIGURE_ARGS+=	--with-uid=${DCCUSER}
SED_SCRIPT=	-e 's|%%PREFIX%%|${PREFIX}|g' \
		-e 's|%%DCCUSER%%|${DCCUSER}|g' -e 's|%%DCCUID%%|${DCCUID}|g' \
		-e 's|%%DCCGROUP%%|${DCCGROUP}|g' -e 's|%%DCCGID%%|${DCCGID}|g'

pre-everything::
	@${ECHO_MSG} ' '
	@${ECHO_MSG} 'You can choose the sendmail to be used by specifying:'
	@${ECHO_MSG} ' '
	@${ECHO_MSG} 'WITH_SENDMAIL_BASE=yes'
	@${ECHO_MSG} 'or'
	@${ECHO_MSG} 'WITH_SENDMAIL_PORT=yes'
	@${ECHO_MSG} 'or'
	@${ECHO_MSG} 'WITHOUT_SENDMAIL=yes'
	@${ECHO_MSG} ''

post-patch:
	${FIND} ${WRKSRC} -type f -exec \
		${REINPLACE_CMD} -e 's,/usr/local,${PREFIX},g' {} \;
	${REINPLACE_CMD} -e 's,PTHREAD_LDFLAGS="$$PTHREAD_LDFLAGS -pthread,PTHREAD_LDFLAGS="$$PTHREAD_LDFLAGS,g' ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's,FreeBSD)\n\tPTHREAD_LDFLAGS,FreeBSD)\n\tDCC_CFLAGS="${PTHREAD_CFLAGS} $$DCC_CFLAGS"\n\tPTHREAD_LDFLAGS,g' ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's,PTHREAD_LIBS="$$PTHREAD_LIBS -lc_r,PTHREAD_LIBS=" ${PTHREAD_LIBS},g' ${WRKSRC}/configure

post-build:
	@${SED} ${SED_SCRIPT} ${PKGDIR}/pkg-install >${PKGINSTALL}
	@${SED} ${SED_SCRIPT} ${PKGDIR}/pkg-deinstall >${PKGDEINSTALL}

pre-install:
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGINSTALL} ${PREFIX} PRE-INSTALL

post-install:
	@[ -s ${HOMEDIR}/dcc_conf ] || \
		${CP} ${HOMEDIR}/dcc_conf.dist ${HOMEDIR}/dcc_conf

.include <bsd.port.post.mk>
