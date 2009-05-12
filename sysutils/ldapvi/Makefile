# New ports collection makefile for:	ldapvi
# Date created:		Mon Apr 24 09:37:02 CEST 2006
# Whom:			Joerg Pulz <Joerg.Pulz@frm2.tum.de>
#
# $FreeBSD$
#

PORTNAME=	ldapvi
PORTVERSION=	1.7
PORTREVISION=	2
CATEGORIES=	sysutils net
MASTER_SITES=	http://www.lichteblau.com/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tool to update LDAP entries with a text editor

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt

USE_OPENLDAP=	yes
USE_GNOME=	pkgconfig glib20
USE_ICONV=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
MAKEFILE=	GNUmakefile

CFLAGS+=	-I${LOCALBASE}/include
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CFLAGS="${CFLAGS}" \
		CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}"

MAN1=		ldapvi.1
PLIST_FILES=	bin/ldapvi \
		${DOCSDIR_REL}/manual.css ${DOCSDIR_REL}/manual.xml \
		${DOCSDIR_REL}/bg.png ${DOCSDIR_REL}/html.xsl
PLIST_DIRS=	${DOCSDIR_REL}

.include <bsd.port.pre.mk>

.if !defined(WANT_OPENLDAP_SASL) || defined(WITHOUT_SASL)
CONFIGURE_ARGS+=--without-sasl
.endif

.include <bsd.port.post.mk>
