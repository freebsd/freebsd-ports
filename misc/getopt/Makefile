# New ports collection makefile for:	getopt
# Date created:	2003-06-05
# Whom:		Sergei Kolobov <sergei@kolobov.com>
#
# $FreeBSD$
#

PORTNAME=	getopt
PORTVERSION=	1.1.3
CATEGORIES=	misc
MASTER_SITES=	http://huizen.dds.nl/~frodol/

MAINTAINER=	sergei@FreeBSD.org
COMMENT=	A getopt(1) replacement that supports GNU-style long options

LIB_DEPENDS=	intl:${PORTSDIR}/devel/gettext-old

USE_GMAKE=		yes
USE_GETOPT_LONG=	yes

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lintl
MAKE_ENV=	LIBCGETOPT=0 CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=		getopt.1
DOCS=		Changelog README

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
