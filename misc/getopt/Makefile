# New ports collection makefile for:	getopt
# Date created:	2003-06-05
# Whom:		Sergei Kolobov <sergei@kolobov.com>
#
# $FreeBSD$
#

PORTNAME=	getopt
PORTVERSION=	1.1.4
PORTREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	http://software.frodo.looijaard.name/getopt/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A getopt(1) replacement that supports GNU-style long options

USE_GETTEXT=		yes
USE_GMAKE=		yes

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lintl
MAKE_ENV=	LIBCGETOPT=0 LDFLAGS="${LDFLAGS}"

MAN1=		getopt.1
DOCS=		Changelog README

post-patch:
	@${REINPLACE_CMD} -e 's|CC=gcc|CC=${CC}|' ${WRKSRC}/Makefile

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
