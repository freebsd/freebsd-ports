# New ports collection makefile for:   dictfmt
# Date created:                19 July 2002
# Whom:                        Kimura Fuyuki <fuyuki@hadaly.org>
#
# $FreeBSD$
#

PORTNAME=	dictfmt
PORTVERSION=	1.9.14
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	dict
DISTNAME=	dictd-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Formats a DICT protocol dictionary database

USE_GETOPT_LONG=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--with-cflags="${CFLAGS}"
ALL_TARGET=	dictfmt
INSTALL_TARGET=	install.dictfmt

MAN1=		dictfmt.1 dictfmt_index2suffix.1 dictfmt_index2word.1 \
		dictunformat.1
PLIST_FILES=	bin/dictfmt bin/dictfmt_index2suffix bin/dictfmt_index2word \
		bin/dictfmt_plugin bin/dictfmt_virtual bin/dictunformat

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		"Does not compile on sparc64"
.endif

.include <bsd.port.post.mk>
