# New ports collection makefile for:   dictfmt
# Date created:                19 July 2002
# Whom:                        Kimura Fuyuki <fuyuki@hadaly.org>
#
# $FreeBSD$
#

PORTNAME=	dictfmt
PORTVERSION=	1.9.10
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	dict
DISTNAME=	dictd-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Formats a DICT protocol dictionary database

LIB_DEPENDS=	ltdl.4:${PORTSDIR}/devel/libltdl

USE_GMAKE=	yes
USE_AUTOCONF_VER=	253
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"
ALL_TARGET=	dictfmt
INSTALL_TARGET=	install.dictfmt

MAN1=		dictfmt.1 dictfmt_index2suffix.1 dictfmt_index2word.1 \
		dictunformat.1

.include <bsd.port.mk>
