# Ports collection makefile for:       	ck4up
# Date created:                 November 19, 2006
# Whom:                        	Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ck4up
PORTVERSION=	0.2.3
CATEGORIES=	sysutils
MASTER_SITES=	http://jue.li/crux/ck4up/

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Checks http and ftp sites for updates

RUN_DEPENDS=	${RUBY_ARCHLIBDIR}/gdbm.so:${PORTSDIR}/databases/ruby-gdbm

NO_BUILD=	yes
USE_RUBY=	yes

MAN1=		ck4up.1

PLIST_DIRS=	%%EXAMPLESDIR%%
PLIST_FILES=	bin/ck4up %%EXAMPLESDIR%%/ck4up.conf

post-patch:
	${RUBY} -i -pe 'gsub /%%PREFIX%%/, "${PREFIX}"' ${WRKSRC}/*

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/ck4up.conf ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
