# ex:ts=8
# Ports collection makefile for:	GNUnet
# Date created:			Mar 23, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gnunet
PORTVERSION=	0.5.1a
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNU} \
		http://www.ovmj.org/GNUnet/download/
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	GNUnet-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An anonymous, distributed, reputation-based network

LIB_DEPENDS=	gdbm.3:${PORTSDIR}/databases/gdbm

USE_BZIP2=	yes
USE_OPENSSL=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
INSTALLS_SHLIB=	yes

MAN1=		gnunet-chat.1 gnunet-check.1 gnunet-download.1 gnunet-gtk.1 \
		gnunet-insert-multi.1 gnunet-insert.1 gnunet-search.1 \
		gnunet-tbench.1 gnunetd.1
MAN5=		gnunet.conf.5

post-patch:
	@${REINPLACE_CMD} -e \
		's|-pthread [\$$]CFLAGS|${PTHREAD_CFLAGS} \$$CFLAGS|g ; \
		 s|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

.include <bsd.port.mk>
