# New ports collection makefile for:	qpopper
# Date created:		1 April 1995
# Whom:			pst
#
# $FreeBSD$
#

PORTNAME=	qpopper
PORTVERSION=	4.0.3
PORTREVISION=	1
CATEGORIES=	mail ipv6
MASTER_SITES=	ftp://ftp.qualcomm.com/eudora/servers/unix/popper/%SUBDIR%/ \
		ftp://sunsite.doc.ic.ac.uk/Mirrors/ftp.qualcomm.com/eudora/servers/unix/popper/%SUBDIR%/
MASTER_SITE_SUBDIR=	. old
DISTNAME=	${PORTNAME}${PORTVERSION}

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 400014
PATCH_SITES=	http://www.imasy.or.jp/~ume/ipv6/
PATCHFILES=	qpopper4.0.3-ipv6-20010504.diff.gz
PATCH_DIST_STRIP=	-p1
.endif

MAINTAINER=	lioux@FreeBSD.org

USE_AUTOCONF=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-lmd -lutil" \
		OS_DEFS="-DSETPROCTITLE ${OS_DEFS}"
CONFIGURE_ARGS=	--enable-apop=${PREFIX}/etc/qpopper/pop.auth \
		--enable-nonauth-file=/etc/ftpusers \
		--with-apopuid=pop --without-gdbm \
		--enable-keep-temp-drop

PLIST_SUB=	EPOPPASSD=${EPOPPASSD}

MAN8=		qpopauth.8 qpopper.8

pre-fetch:
.if defined(APOP_ONLY)
	@${ECHO_MSG} "==> The APOP_ONLY option is deprecated, please use"
	@${ECHO_MSG} "	WITH_APOP_ONLY instead."
	@${ECHO_MSG} "==> The APOP_ONLY option will work in this version but"
	@${ECHO_MSG} "	not on future ones."
.endif
.if defined(FULL_POPD_DEBUG)
	@${ECHO_MSG} "==> The FULL_POPD_DEBUG option is deprecated, please"
	@${ECHO_MSG} "	use WITH_FULL_POPD_DEBUG instead."
	@${ECHO_MSG} "==> The FULL_POPD_DEBUG option will work in this version but"
	@${ECHO_MSG} "	not on future ones."
.endif
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You may use the following build options:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "WITH_APOP_ONLY=yes	builds with APOP authentication only"
	@${ECHO_MSG} "WITH_FULL_POPD_DEBUG=yes	buils with more verbose debugging"
	@${ECHO_MSG} "WITH_POPPASSD=yes		builds the poppassd daemon"

# If WITH_APOP_ONLY variable present in the environment, qpopper builds
# with APOP authentication only.
.if defined(APOP_ONLY) || defined(WITH_APOP_ONLY)
OS_DEFS+=	-DAPOP_ONLY
.endif

# If WITH_FULL_POPD_DEBUG variable present in the environment, qpopper builds
# with more verbose debugging. See also -d option to qpopper
.if defined(FULL_POPD_DEBUG) || defined(WITH_FULL_POPD_DEBUG)
CONFIGURE_ARGS+=	--enable-debugging
.endif

# If WITH_POPPASSD variable present in the environment, qpopper builds
# with poppassd support.
.if defined(WITH_POPPASSD)
CONFIGURE_ARGS+=	--enable-poppassd
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-password::poppassd.c
EPOPPASSD=	""
.else
EPOPPASSD=	"@comment "
.endif

.if exists(/usr/lib/libssl.a) && exists(/usr/lib/libcrypto.a)
CONFIGURE_ARGS+=	--with-openssl=/usr
.elif exists(${LOCALBASE}/lib/libssl.a) && exists(${LOCALBASE}/lib/libcrypto.a)
LIB_DEPENDS+=	ssl.2:${PORTSDIR}/security/openssl
CONFIGURE_ARGS+=	-with-includes=${LOCALBASE}/include/openssl --with-openssl=${LOCALBASE}
CONFIGURE_ENV+=	RSAGLUE="${RSAGLUE}"
.if exists(${LOCALBASE}/lib/librsaref.a)
RSAGLUE=	-lrsaref
.endif
RSAGLUE+=	-lRSAglue
.endif

post-patch:
	@${RM} -f ${WRKSRC}/popper/md5.h
	@${PERL} -pi -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/man/*
.if defined(WITH_POPPASSD)
	@${PERL} -pi -ne "s|/usr/bin/smbpasswd|${PREFIX}/bin/smbpasswd|" \
		${WRKSRC}/password/poppassd.c
.endif

pre-configure:
	@(cd ${WRKSRC}; ${CHMOD} u+w configure*)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/popper/popauth ${PREFIX}/bin/qpopauth
	${INSTALL_PROGRAM} ${WRKSRC}/popper/popper ${PREFIX}/libexec/qpopper
	${INSTALL_MAN} ${WRKSRC}/man/popauth.8 ${MANPREFIX}/man/man8/qpopauth.8
	${INSTALL_MAN} ${WRKSRC}/man/popper.8 ${MANPREFIX}/man/man8/qpopper.8
	${LN} -sf ${PREFIX}/bin/qpopauth ${PREFIX}/bin/qapopauth
.if defined(WITH_POPPASSD)
	${INSTALL_PROGRAM} ${WRKSRC}/password/poppassd ${PREFIX}/libexec/qpoppassd
.endif

post-install:
	@${SED} -e "s:/usr/local:${PREFIX}:g" ${PKGMESSAGE}

.include <bsd.port.post.mk>
