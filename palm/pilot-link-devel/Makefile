# New ports collection makefile for:    pilot-link
# Date created:         November, 1997
# Whom:                 Paul Traina <pst@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pilot-link
PORTVERSION=	0.11.8
PORTREVISION=	1
CATEGORIES=	palm comms tk83
MASTER_SITES=	http://oss.redundant.com/pub/gentoo/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PalmPilot communications utilities (backup/restore/install/debug/...)

LIB_DEPENDS=	tk83:${PORTSDIR}/x11-toolkits/tk83 \
		iconv.3:${PORTSDIR}/converters/libiconv

USE_GETOPT_LONG=yes
USE_BZIP2=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
USE_PERL5=	yes

CFLAGS+=	-I${LOCALBASE}/include
HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-perl5=${PERL5} --with-libiconv=${LOCALBASE} --with-tclinclude=${LOCALBASE}/include/tcl8.3/ --with-tcl=${LOCALBASE}/lib/tcl8.3/ --program-transform-name=
CONFIGURE_ENV+=	LDFLAGS="-L${LOCALBASE}/lib"

.include "${.CURDIR}/manpages.mk"

.include <bsd.port.mk>
