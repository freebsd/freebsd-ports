# New ports collection makefile for:    pilot-link
# Date created:         November, 1997
# Whom:                 Paul Traina <pst@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pilot-link
PORTVERSION=	0.11.7
CATEGORIES=	palm comms tk83
MASTER_SITES=	http://www.pilot-link.org/source/

MAINTAINER=	dima@FreeBSD.org

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt \
		tk83:${PORTSDIR}/x11-toolkits/tk83 \
		iconv.3:${PORTSDIR}/converters/libiconv

USE_BZIP2=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
USE_PERL5=	yes

MAN1=		dlpsh.1 ietf2datebook.1 install-datebook.1 \
		install-hinote.1 install-memo.1 install-user.1 \
		pilot-addresses.1 pilot-xfer.1 read-ical.1
MAN7=		pilot-link.7

CFLAGS+=		-I${LOCALBASE}/include -I${LOCALBASE}/include/tcl8.3
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-perl5=${PERL5} --with-libiconv=${LOCALBASE}
CONFIGURE_ENV=	LIBS="-lgnugetopt" LDFLAGS="-L${LOCALBASE}/lib"
MAKE_ARGS=	LIBTOOL=libtool

.include <bsd.port.mk>
