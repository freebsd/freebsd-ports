# Ports collection makefile for:       	ck4up
# Date created:                 November 19, 2006
# Whom:                        	Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ck4up
PORTVERSION=	1.1
CATEGORIES=	sysutils
MASTER_SITES=	http://jue.li/crux/ck4up/

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Checks http and ftp sites for updates

RUN_DEPENDS=	${RUBY_ARCHLIBDIR}/gdbm.so:${PORTSDIR}/databases/ruby-gdbm

NO_BUILD=	yes
USE_RUBY=	yes
RUBY_VER=	1.8
RUBY_NO_BUILD_DEPENDS=	yes

MAN1=		ck4up.1

PORTEXAMPLES=	ck4up.conf

PLIST_FILES=	bin/ck4up

post-patch:
	@${REINPLACE_CMD} -e 's|/usr|${LOCALBASE}|g' \
	    ${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/ck4up.conf ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
