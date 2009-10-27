# ex:ts=8
# New ports collection makefile for:	botan
# Date created:			Mar 3, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	botan
PORTVERSION=	1.8.7
CATEGORIES=	security
MASTER_SITES=	http://files.randombit.net/botan/v1.8/
DISTNAME=	Botan-${PORTVERSION}
EXTRACT_SUFX=	.tbz

MAINTAINER=	lapo@lapo.it
COMMENT=	A portable, easy to use, and efficient C++ crypto library

OPTIONS=	ECC "Enable ECC support" on

USE_BZIP2=	yes
USE_PYTHON_BUILD=	yes
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	configure.py
CONFIGURE_ARGS=	--prefix=${PREFIX} --with-tr1-implementation=boost
USE_GMAKE=	yes
MAKE_ARGS=	CXX="${CXX}" LIB_OPT="${CXXFLAGS}"
USE_LDCONFIG=	yes

PLIST_SUB=	SOVERSION=1.8.2

PORTDOCS=	*

.include <bsd.port.options.mk>

.if !defined(WITHOUT_ECC)
BUILD_DEPENDS+=	${LOCALBASE}/include/boost/tr1/memory.hpp:${PORTSDIR}/devel/boost-libs
CONFIGURE_ARGS+=--with-tr1-implementation=boost
CXXFLAGS+=	-I${LOCALBASE}/include
PLIST_SUB+=	ECC=""
.else
CONFIGURE_ARGS+=--with-tr1-implementation=none
PLIST_SUB+=	ECC="@comment "
.endif

.if defined(NOPORTDOCS)
post-patch:
	${REINPLACE_CMD} -e '/$$(MKDIR_INSTALL) $$(DOCDIR)/d' \
			-e '/$$(INSTALL_CMD_DATA) $$$$i $$(DOCDIR); /d' \
			${WRKSRC}/src/build-data/makefile/unix_shr.in
.endif

.include <bsd.port.mk>
