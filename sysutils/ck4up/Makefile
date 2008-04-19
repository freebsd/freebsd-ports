# Ports collection makefile for:       	ck4up
# Date created:                 November 19, 2006
# Whom:                        	Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ck4up
PORTVERSION=	1.0
CATEGORIES=	sysutils
MASTER_SITES=	http://jue.li/crux/ck4up/

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Checks http and ftp sites for updates

RUN_DEPENDS=	${RUBY_ARCHLIBDIR}/gdbm.so:${PORTSDIR}/databases/ruby-gdbm

NO_BUILD=	yes
USE_RUBY=	yes
RUBY_VER=	1.8
RUBY_NO_BUILD_DEPENDS=	yes
RUBY_SHEBANG_FILES=	ck4up.rb

MAN1=		ck4up.1

PLIST_DIRS=	%%EXAMPLESDIR%%
PLIST_FILES=	bin/ck4up %%EXAMPLESDIR%%/ck4up.conf

post-patch:
	@${REINPLACE_CMD} -e "s:%%PREFIX%%:${PREFIX}:g" ${WRKSRC}/*

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/ck4up.conf ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
