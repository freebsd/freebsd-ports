# ex:ts=8
# Ports collection makefile for:	GNUnet
# Date created:			Mar 23, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gnunet
PORTVERSION=	0.4.6
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	GNUnet-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	gdbm.2:${PORTSDIR}/databases/gdbm

USE_BZIP2=	yes
USE_OPENSSL=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		gnunet-check.1 gnunet-download.1 gnunet-gtk.1 \
		gnunet-insert-multi.1 gnunet-insert.1 gnunet-search.1 gnunetd.1
MAN5=		gnunet.conf.5

post-patch:
	@${REINPLACE_CMD} -e \
		's|-pthread [\$$]CFLAGS|${PTHREAD_CFLAGS} \$$CFLAGS|g ; \
		 s|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

.include <bsd.port.mk>
