# ex:ts=8
# New ports collection makefile for:	redland
# Date created:			Nov 22, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	redland
PORTVERSION=	0.9.12
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.redland.opensource.ac.uk/dist/source/
MASTER_SITE_SUBDIR=	librdf

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A high-level interface for RDF

LIB_DEPENDS=	db2.0:${PORTSDIR}/databases/db2 \
		expat.4:${PORTSDIR}/textproc/expat2 \
		xml2.5:${PORTSDIR}/textproc/libxml2 \
		xmlparse.1:${PORTSDIR}/www/libwww

LIBWWW_CONFIG?=	${LOCALBASE}/bin/libwww-config

USE_OPENSSL=	yes
USE_PERL5=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include/db2 -I${LOCALBASE}/include"
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-bdb=${LOCALBASE} --with-libwww
INSTALLS_SHLIB=	yes

MAN1=		rapper.1
MAN3=		libraptor.3 redland.3

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${PERL} -pi -e \
		's|\@INSTALL\@|/usr/bin/install -c|g ; \
		 s|^CPPFLAGS = -I|CPPFLAGS = \@CPPFLAGS\@ -I|g ; \
		 s|^LDFLAGS = \@LIBRDF_|LDFLAGS = \@LDFLAGS\@ \@LIBRDF_|g ; \
		 s|^LIBS = \@LIBRDF_|LIBS = \@LIBS\@ \@LIBRDF_|g'

.include <bsd.port.mk>
