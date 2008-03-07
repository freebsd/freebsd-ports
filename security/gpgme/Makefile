# New ports collection makefile for:	gpgme
# Date created:		15 June 2001
# Whom:			teramoto@comm.eng.osaka-u.ac.jp
#
# $FreeBSD$
#

PORTNAME=	gpgme
PORTVERSION=	1.1.5
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNUPG}
MASTER_SITE_SUBDIR=	gpgme

MAINTAINER=	lofi@FreeBSD.org
COMMENT=	A library to make access to GnuPG easier

BUILD_DEPENDS=	gpg2:${PORTSDIR}/security/gnupg
LIB_DEPENDS=	gpg-error.0:${PORTSDIR}/security/libgpg-error
RUN_DEPENDS=	gpg2:${PORTSDIR}/security/gnupg

USE_AUTOTOOLS=	libtool:15
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-gpg=${LOCALBASE}/bin/gpg \
		--with-gpgsm=${LOCALBASE}/bin/gpgsm \
		--includedir=${PREFIX}/include/gpgme

INFO=		gpgme

OPTIONS=	PTH "Enable alternative libgpgme using GNU portable threads" off

.include <bsd.port.pre.mk>

.if defined(WITH_PTH)
LIB_DEPENDS+=	pth:${PORTSDIR}/devel/pth
PLIST_SUB+=	WITH_PTH=''
.elif defined(WITHOUT_PTH)
CONFIGURE_ARGS+=--without-pth --without-pth-test
PLIST_SUB+=	WITH_PTH='@comment '
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|EOF||g' ${WRKSRC}/assuan/assuan-errors.c
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' \
					${WRKSRC}/${CONFIGURE_SCRIPT} \
					${WRKSRC}/gpgme/Makefile.in \
					${WRKSRC}/gpgme/gpgme-config.in
	@${REINPLACE_CMD} -e 's|^clfilesdir.*|clfilesdir=$$\(libdir\)/common-lisp/gpgme|g' \
					${WRKSRC}/lang/cl/Makefile.in
.if defined(WITH_PTH)
.if ${OSVERSION} < 503100 || defined(PTHREAD_LIBS) && ${PTHREAD_LIBS} != "-pthread"
	@${REINPLACE_CMD} -e 's|t_thread1_LDADD = ../../gpgme/libgpgme-pthread.la|t_thread1_LDADD = ../../gpgme/libgpgme-pthread.la -lpthread|g' \
					${WRKSRC}/tests/gpg/Makefile.in
.endif
.endif

.include <bsd.port.post.mk>
