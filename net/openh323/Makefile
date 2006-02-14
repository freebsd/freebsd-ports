# New ports collection makefile for:	openh323
# Date created:		Thu Feb 17 15:00:48 GMT 2000
# Whom:			Roger Hardiman <roger@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	openh323
PORTVERSION=	1.17.3
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.voxgratia.org/releases/
DISTFILES=	openh323-v1_17_3-src-tar.gz

MAINTAINER=	steve@energistic.com
COMMENT=	A H323 Video Conferencing library

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2 \
		pt_r.1:${PORTSDIR}/devel/pwlib

WRKSRC=	${WRKDIR}/openh323_v1_17_3

USE_BISON=	yes
USE_GMAKE=	yes
USE_OPENLDAP=	yes
USE_AUTOTOOLS=	autoconf:259
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include -I${WRKSRC}/include" LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib" BUILDTIME="YES"
NO_FILTER_SHLIBS=	yes
ALL_TARGET=	optshared
MAKE_ENV=	BUILDTIME="YES"

.include <bsd.port.mk>
