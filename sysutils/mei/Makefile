# New ports collection makefile for:	mei
# Date created:		19 Sep 1997
# Whom:			itojun@itojun.org
#
# $FreeBSD$
#

PORTNAME=	mei
PORTVERSION=	1.53
CATEGORIES=	sysutils
MASTER_SITES=	http://www.vector.co.jp/authors/VA001240/archive/
DISTFILES=	mei153s.tgz mei153d.tgz

MAINTAINER=	ports@freebsd.org

BUILD_DEPENDS=	nkf:${PORTSDIR}/japanese/nkf

MAN1=	mei.1 moe.1
MANLANG=	"" ja

NO_WRKSUBDIR=	yes
MAKEFILE=	freebsd.mak
MAKE_ENV+=	INSTALL_PROGRAM="$(INSTALL_PROGRAM)" \
		INSTALL_MAN="$(INSTALL_MAN)"
INSTALL_TARGET=	install install.man

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 300000
BROKEN=		not support CAM
.endif

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${PREFIX}/share/doc/mei
	${INSTALL_DATA} ${WRKSRC}/*txt ${PREFIX}/share/doc/mei
.endif

.include <bsd.port.post.mk>
