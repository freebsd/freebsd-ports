# New ports collection makefile for:		node
# Date created:					2010-04-12
# Whom:						Jin-Sih Lin <linpct@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	node
PORTVERSION=	0.7.9
CATEGORIES=	www
MASTER_SITES=	http://nodejs.org/dist/v${PORTVERSION}/
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	linpct@gmail.com
COMMENT=	V8 javascript for client and server

LIB_DEPENDS=	execinfo.1:${PORTSDIR}/devel/libexecinfo

MAN1=		node.1

HAS_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_PYTHON=	2.7
USE_GMAKE=	yes

CONFLICTS=	node-0.[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
MAKE_JOBS_SAFE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX_RELDEST} --without-npm
PREFIX_RELDEST=	${PREFIX:S,^${DESTDIR},,}

post-patch:
	@${RM} ${WRKSRC}/tools/wafadmin/Node.py.orig

post-install:
	${MKDIR} ${PREFIX}/lib/node_modules/
	${TOUCH} ${PREFIX}/lib/node_modules/.keepme
	${INSTALL_MAN} ${WRKSRC}/doc/node.1 ${MANPREFIX}/man/man1/
	@${ECHO_MSG}
	@${ECHO_MSG} "Note: If you need npm (Node Package Manager), please install www/npm."
	@${ECHO_MSG}

.include <bsd.port.mk>
