# New ports collection makefile for:		node
# Date created:					2010-04-12
# Whom:						Jin-Sih Lin <linpct@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	node
PORTVERSION=	0.8.5
CATEGORIES=	www
MASTER_SITES=	http://nodejs.org/dist/v${PORTVERSION}/
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	linpct@gmail.com
COMMENT=	V8 JavaScript for client and server

LIB_DEPENDS=	execinfo:${PORTSDIR}/devel/libexecinfo

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
REINPLACE_ARGS=	-i ''

post-patch:
	@${RM} ${WRKSRC}/tools/wafadmin/Node.py.orig
	@${REINPLACE_CMD} -e 's|share/man/man1/|man/man1|' ${WRKSRC}/tools/installer.js

post-install:
	${MKDIR} ${PREFIX}/lib/node_modules/
	${TOUCH} ${PREFIX}/lib/node_modules/.keepme
	${CHMOD} ${MANMODE} ${PREFIX}/man/man1/node.1
	@${ECHO_MSG}
	@${ECHO_MSG} "Note: If you need npm (Node Package Manager), please install www/npm."
	@${ECHO_MSG}

.include <bsd.port.mk>
