# New ports collection makefile for:   dictfmt
# Date created:                19 July 2002
# Whom:                        Kimura Fuyuki <fuyuki@hadaly.org>
#
# $FreeBSD$
#

PORTNAME=	dictfmt
PORTVERSION=	1.9.8
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	dict
DISTNAME=	dictd-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Formats a DICT protocol dictionary database

BUILD_DEPENDS=	aclocal:${PORTSDIR}/devel/automake

USE_AUTOCONF=	yes
WANT_AUTOCONF_VER=	253
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include"
USE_GMAKE=	yes
ALL_TARGET=	dictfmt
INSTALL_TARGET=	install.dictfmt

MAN1=		dictfmt.1 dictfmt_index2suffix.1 dictfmt_index2word.1 \
		dictunformat.1

post-patch:
	cd ${WRKSRC}; aclocal; ${AUTOHEADER}

.include <bsd.port.mk>
