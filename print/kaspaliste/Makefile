# New ports collection makefile for:	kaspaliste
# Date created:				16 December 2003
# Whom:					jaapb
#
# $FreeBSD$
#

PORTNAME=		kaspaliste
PORTVERSION=		0.94
PORTREVISION=	1
CATEGORIES=		print kde
MASTER_SITES=		http://kaspaliste.sourceforge.net/

MAINTAINER=		jaapb@kerguelen.org
COMMENT=		Bibliography tool for KDE/Postgres/BibTeX

LIB_DEPENDS= \
		pq.3:${PORTSDIR}/databases/postgresql-client

USE_BZIP2=		yes
USE_KDEBASE_VER=	3
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
CONFIGURE_TARGET=
CONFIGURE_ARGS+=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}	\
			--with-pg-includes=${LOCALBASE}/include \
			--with-pg-libs=${LOCALBASE}/lib

.include <bsd.port.mk>
