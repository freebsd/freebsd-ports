# New ports collection makefile for:	jabberd
# Date created:				29 December 2003
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jabberd
PORTVERSION=	2.0.1
CATEGORIES=	net
MASTER_SITES=	http://www.jabberstudio.org/files/jabberd2/
DISTNAME=	${PORTNAME}-2.0s1
DIST_SUBDIR=	jabber

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Online presence and instant messaging server

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-openssl=/usr \
		--with-libiconv-prefix=${LOCALBASE}

.if defined(WITH_BDB)
LIB_DEPENDS+=	db41.1:${PORTSDIR}/databases/db41
CONFIGURE_ARGS+=--with-berkeley-db=${LOCALBASE} \
		--enable-storage=db \
		--enable-authreg=db
LDFLAGS+=	-ldb41
CFLAGS+=	-I${LOCALBASE}/include/db41
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
CONFIGURE_ARGS+=--with-mysql=${LOCALBASE} \
		--enable-storage=mysql \
		--enable-authreg=mysql
.endif

.if defined(WITH_LDAP)
USE_OPENLDAP=	yes
.endif

MAN8=		c2s.8 jabberd.8 resolver.8 router.8 s2s.8 sm.8

.include <bsd.port.mk>
