# New ports collection makefile for:	dazuko
# Date created:				01 March 2004
# Whom:					Rob Evers <rob@debank.tv>
#
# $FreeBSD$

PORTNAME=	dazuko
PORTVERSION=	2.0.2
CATEGORIES=	security
MASTER_SITES=	http://dazuko.org/files/

MAINTAINER=	rob@debank.tv
COMMENT=	A common interface for 3rd party file access control

HAS_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if !${OSVERSION} < 500000
IGNORE=	"Only compiles on 4.x"
.endif

do-install:
	${MKDIR} ${PREFIX}/modules/
	${INSTALL_DATA} ${WRKSRC}/dazuko.ko ${PREFIX}/modules/dazuko.ko

post-install:
	${SH} ${PKGINSTALL} ${PREFIX} POST-INSTALL

.include <bsd.port.post.mk>
