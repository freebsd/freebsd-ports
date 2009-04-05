# ex:ts=8
# New ports collection makefile for:	botan
# Date created:			Mar 3, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	botan
PORTVERSION=	1.6.5
CATEGORIES=	security
MASTER_SITES=	http://files.randombit.net/botan/v1.6/
DISTNAME=	Botan-${PORTVERSION}
EXTRACT_SUFX=	.tbz

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	A portable, easy to use, and efficient C++ crypto library

USE_BZIP2=	yes
USE_PERL5=	yes
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	configure.pl
CONFIGURE_ARGS=	--prefix=${PREFIX} gcc-freebsd-generic
USE_GMAKE=	yes
MAKE_ARGS=	CXX="${CXX}" LIB_OPT="${CXXFLAGS}" \
		LANG_FLAGS="-fpermissive"
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

.if !defined(NOPORTDOCS)
DOCSDIR=	${PREFIX}/share/doc/Botan-${PORTVERSION}
PORTDOCS=	*
.else
post-configure:
	${REINPLACE_CMD} -e '/$$(MKDIR_INSTALL) $$(DOCDIR)/d' \
			-e '/$$(INSTALL_CMD_DATA) $$$$i $$(DOCDIR); /d' \
			${WRKSRC}/Makefile
.endif

.include <bsd.port.mk>
