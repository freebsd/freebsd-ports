# ex:ts=8
# New ports collection makefile for:	redland
# Date created:			Nov 22, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	redland
PORTVERSION=	0.9.13
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.redland.opensource.ac.uk/dist/source/
MASTER_SITE_SUBDIR=	librdf

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A high-level interface for RDF

LIB_DEPENDS=	db2.0:${PORTSDIR}/databases/db2 \
		raptor.0:${PORTSDIR}/textproc/raptor

USE_OPENSSL=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--with-bdb-lib="${LOCALBASE}/lib" \
		--with-bdb-include="${LOCALBASE}/include/db2" \
		--with-bdb-dbname="db2" \
		--with-libwww
INSTALLS_SHLIB=	yes

MAN1=		redland-config.1 redland-db-upgrade.1
MAN3=		redland.3

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|ac_subdirs_all raptor|ac_subdirs_all|g ; \
		 s|-I\\$$(top_srcdir)/raptor||g ; \
		 s|\\$$(top_builddir)/raptor/libraptor.la|-lraptor|g' \
			${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|SUBDIRS = raptor|SUBDIRS =|g ; \
		 s|$$(top_builddir)/raptor/libraptor.la|-lraptor|g'

.include <bsd.port.mk>
