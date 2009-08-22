# New ports collection makefile for:    libpwstor
# Date created:                         2008-10-23
# Whom:                                 Matt Harris <mattdharris@users.sourceforge.net>
#
# $FreeBSD$
#

PORTNAME=       libpwstor
PORTVERSION=    0.1
CATEGORIES=     security devel
MASTER_SITES=   SF/kageki/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=     ports@FreeBSD.org
COMMENT=        A password storage library for C programmers

USE_BZIP2=      yes
USE_LDCONFIG=   yes
GNU_CONFIGURE=  yes

PLIST_FILES=	bin/pwtool \
		include/pwstor.h \
		lib/libpwstor.a \
		lib/libpwstor.so \
		lib/libpwstor.so.0.1

MANCOMPESSED=	no
MAN1=		pwtool.1
MAN3=		pwstor.3 \
		pws_version.3 \
		pws_version_int.3 \
		pws_rand_get.3 \
		pws_memnuke.3 \
		pws_base64_encode.3 \
		pws_base64_decode.3 \
		pws_passwords_encode.3 \
		pws_passwords_encodemulti.3 \
		pws_passwords_len.3 \
		pws_passwords_check.3 \
		pws_passwords_checkmulti.3 \
		pws_passwords_converttomulti.3

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
CFLAGS+=	-fPIC -DPIC
.endif

.if ${OSVERSION} < 700000
BROKEN=		does not compile on FreeBSD 6.x
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=        --enable-debug
.endif

.include <bsd.port.post.mk>
