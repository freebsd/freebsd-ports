# New ports collection makefile for:	mei
# Version required:	1.53
# Date created:		19 Sep 1997
# Whom:			itojun@itojun.org
#
# $Id: Makefile,v 1.1.1.1 1997/09/19 02:13:54 itojun Exp $
#

DISTNAME=	mei-1.53
CATEGORIES=	sysutils
MASTER_SITES=	http://www.vector.co.jp/authors/VA001240/archive/
DISTFILES=	mei153s.tgz mei153d.tgz

MAINTAINER=	itojun@itojun.org

BUILD_DEPENDS=	nkf:${PORTSDIR}/nkf

MAN1=	mei.1 moe.1
MANLANG=	"" ja_JP.EUC

NO_WRKSUBDIR=	yes
MAKEFILE=	freebsd.mak
MAKE_ENV+=	INSTALL_PROGRAM="$(INSTALL_PROGRAM)" \
		INSTALL_MAN="$(INSTALL_MAN)"
INSTALL_TARGET=	install install.man

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} -p ${PREFIX}/share/doc/mei
	${INSTALL_DATA} ${WRKSRC}/*txt ${PREFIX}/share/doc/mei
.endif

.include <bsd.port.mk>
