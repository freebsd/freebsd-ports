# ex:ts=8
# New ports collection makefile for:	redland
# Date created:			Nov 22, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	redland
PORTVERSION=	0.9.15
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.redland.opensource.ac.uk/dist/source/
MASTER_SITE_SUBDIR=	librdf

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A high-level interface for RDF

LIB_DEPENDS=	db41.1:${PORTSDIR}/databases/db41 \
		raptor.2:${PORTSDIR}/textproc/raptor

USE_GNOME=	gnomehack gnometarget pkgconfig
USE_OPENSSL=	yes
USE_GETOPT_LONG=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--with-bdb-lib="${LOCALBASE}/lib" \
		--with-bdb-include="${LOCALBASE}/include/db41" \
		--with-bdb-dbname="db41" \
		--with-libwww \
		--with-raptor=system
INSTALLS_SHLIB=	yes

MAN1=		rdfproc.1 redland-config.1 redland-db-upgrade.1
MAN3=		redland.3

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
