# New ports collection makefile for:    console-licq
# Date created:                         18 October 2000
# Whom:                                 Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	console
PORTVERSION=	${CONSOLE_LICQ_VER}
CATEGORIES=	net-im

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Ncurses-based console plugin for Licq

LIB_DEPENDS=	cdk.5:${PORTSDIR}/devel/cdk \
		boost_regex.4:${PORTSDIR}/devel/boost-libs

LICENSE=	GPLv2

USE_CMAKE=	yes
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

DOCFILES=	README
PLIST_FILES=	lib/licq/licq_console.so \
		%%PORTDOCS%%%%DOCSDIR%%/README
PLIST_DIRS=	%%PORTDOCS%%%%DOCSDIR%%

LICQ_PORT?=	net-im/licq

.include <bsd.port.pre.mk>

.include "${PORTSDIR}/${LICQ_PORT}/Makefile.inc"

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/
.endif

.include <bsd.port.post.mk>
