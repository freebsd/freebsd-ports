# New ports collection makefile for:	diradmin
# Date created:		24 April 2003
# Whom:			lewiz <purple@lewiz.info>
#
# $FreeBSD$
#

PORTNAME=	diradmin
PORTVERSION=	1.3.5
CATEGORIES=	net
MASTER_SITES=	http://diradmin.open-it.org/
DISTNAME=	directory_administrator-${PORTVERSION}

MAINTAINER=	purple@lewiz.info
COMMENT=	A smart LDAP directory management tool

LIB_DEPENDS+=	ldap.2:${PORTSDIR}/net/openldap20-client
#CPPFLAGS+=	-I/usr/src/lib/libcrypt

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomelibs
CFLAGS+=	-I/usr/src/lib/libcrypt

DOCS=		AUTHORS COPYING CREDITS ChangeLog INSTALL NEWS \
       		README TODO

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
