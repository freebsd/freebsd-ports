# New ports collection makefile for:	diradmin
# Date created:		24 April 2003
# Whom:			Lewis Thompson <purple@lewiz.net>
#
# $FreeBSD$
#

PORTNAME=	diradmin
PORTVERSION=	1.5.1
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://diradmin.open-it.org/
DISTNAME=	directory_administrator-${PORTVERSION}

MAINTAINER=	purple@lewiz.net
COMMENT=	A smart LDAP directory management tool

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomelibs
USE_OPENLDAP=	yes
CFLAGS+=	-I/usr/src/lib/libcrypt

PORTDOCS=	AUTHORS CREDITS ChangeLog INSTALL NEWS \
       		README TODO

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
