# New ports collection makefile for:	security/openvpn-auth-radius
# Date created:		2011-03-04
# Whom:			Mikhail T. <m.tsatsenko@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	openvpn-auth-radius
PORTVERSION=	2.1
CATEGORIES=	security
MASTER_SITES=	http://www.nongnu.org/radiusplugin/ \
		http://svn-cache.ipcopaddons.org/
DISTNAME=	radiusplugin_v${PORTVERSION}

MAINTAINER=	m.tsatsenko@gmail.com
COMMENT=	RADIUS authentication plugin for OpenVPN

RUN_DEPENDS=	openvpn:${PORTSDIR}/security/openvpn
LIB_DEPENDS=	gcrypt.17:${PORTSDIR}/security/libgcrypt

LICENCE=	GPLv2

USE_GMAKE=	yes
MAKEFILE=	Makefile.bsd
WRKSRC=		${WRKDIR}/radiusplugin

PORTDOCS=	README
PORTEXAMPLES=	radiusplugin.cnf
PLIST_FILES=	lib/radiusplugin.so

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_LIB} ${WRKSRC}/radiusplugin.so ${LOCALBASE}/lib

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/radiusplugin.cnf ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
