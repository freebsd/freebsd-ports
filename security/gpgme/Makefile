# New ports collection makefile for:	gpgme
# Date created:		15 June 2001
# Whom:			teramoto@comm.eng.osaka-u.ac.jp
#
# $FreeBSD$
#

PORTNAME=	gpgme
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNUPG}
MASTER_SITE_SUBDIR=	gpgme

MAINTAINER=	lofi@FreeBSD.org
COMMENT=	A library to make access to GnuPG easier

BUILD_DEPENDS=	gpg:${PORTSDIR}/security/gnupg \
		gpgsm:${PORTSDIR}/security/gnupg-devel

LIB_DEPENDS=	gpg-error:${PORTSDIR}/security/libgpg-error \
		pth.20:${PORTSDIR}/devel/pth

USE_LIBTOOL_VER=15
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-gpg=${LOCALBASE}/bin/gpg \
		--with-gpgsm=${LOCALBASE}/bin/gpgsm
	
INFO=	gpgme

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' \
					${WRKSRC}/${CONFIGURE_SCRIPT} \
					${WRKSRC}/gpgme/Makefile.in \
					${WRKSRC}/gpgme/gpgme-config.in
	@${REINPLACE_CMD} -e 's|@RUN_GPG_TESTS_TRUE@tests = tests|@RUN_GPG_TESTS_TRUE@tests =|g' \
					${WRKSRC}/Makefile.in

.include <bsd.port.mk>
