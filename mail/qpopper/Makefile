# New ports collection makefile for:	qpopper
# Date created:		1 April 1995
# Whom:			pst
#
# $FreeBSD$
#

PORTNAME=	qpopper
PORTVERSION=	4.0
PORTREVISION=	1
CATEGORIES=	mail ipv6
MASTER_SITES=	ftp://ftp.qualcomm.com/eudora/servers/unix/popper/ \
		ftp://sunsite.doc.ic.ac.uk/Mirrors/ftp.qualcomm.com/eudora/servers/unix/popper/
DISTNAME=	${PORTNAME}${PORTVERSION}

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 400014
PATCH_SITES=	http://www.imasy.or.jp/~ume/ipv6/
PATCHFILES=	qpopper4.0-ipv6-20010418.diff.gz
PATCH_DIST_STRIP=	-p1
.endif

MAINTAINER=	lioux@FreeBSD.org

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-lmd -lutil" \
		OS_DEFS="-DSETPROCTITLE ${OS_DEFS}"
CONFIGURE_ARGS=	--enable-apop=${PREFIX}/etc/qpopper/pop.auth \
		--enable-nonauth-file=/etc/ftpusers \
		--with-apopuid=pop \
		--enable-keep-temp-drop

MAN8=		qpopauth.8 qpopper.8

# If APOP_ONLY variable present in the environment, qpopper builds
# with APOP authentification only.
.if defined(APOP_ONLY)
OS_DEFS+=	-DAPOP_ONLY
.endif

# If FULL_POPD_DEBUG variable present in the environment, qpopper builds
# with more verbose debugging. See also -d option to qpopper
.if defined(FULL_POPD_DEBUG)
CONFIGURE_ARGS+=	--enable-debugging
.endif

.if exists(/usr/lib/libssl.a) && exists(/usr/lib/libcrypto.a)
CONFIGURE_ARGS+=	--with-openssl=/usr
.elif exists(${LOCALBASE}/lib/libssl.a) && exists(${LOCALBASE}/lib/libcrypto.a)
LIB_DEPENDS+=	ssl.1:${PORTSDIR}/security/openssl
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

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/popper/popauth ${PREFIX}/bin/qpopauth
	${INSTALL_PROGRAM} ${WRKSRC}/popper/popper ${PREFIX}/libexec/qpopper
	${INSTALL_MAN} ${WRKSRC}/man/popauth.8 ${MANPREFIX}/man/man8/qpopauth.8
	${INSTALL_MAN} ${WRKSRC}/man/popper.8 ${MANPREFIX}/man/man8/qpopper.8
	${LN} -sf ${PREFIX}/bin/qpopauth ${PREFIX}/bin/qapopauth

post-install:
	@${SED} -e "s:/usr/local:${PREFIX}:g" ${PKGMESSAGE}

.include <bsd.port.post.mk>
