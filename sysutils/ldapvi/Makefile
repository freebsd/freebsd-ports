# New ports collection makefile for:	ldapvi
# Date created:		Mon Apr 24 09:37:02 CEST 2006
# Whom:			Joerg Pulz <Joerg.Pulz@frm2.tum.de>
#
# $FreeBSD$
#

PORTNAME=	ldapvi
PORTVERSION=	1.5
CATEGORIES=	sysutils net
MASTER_SITES=	http://www.lichteblau.com/download/

MAINTAINER=	Joerg.Pulz@frm2.tum.de
COMMENT=	A tool to update LDAP entries with a text editor

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt

USE_OPENLDAP=	yes
USE_GNOME=	pkgconfig glib20
USE_ICONV=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
MAKEFILE=	GNUmakefile

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CFLAGS="${CFLAGS}" \
		LDFLAGS="${LDFLAGS}"

MAN1=		ldapvi.1
PLIST_FILES=	bin/ldapvi

.include <bsd.port.pre.mk>

.ifdef(WANT_OPENLDAP_SASL) && !defined(WITHOUT_SASL)
PATCH_SITES=	http://w3.gofti.com/~pfnguyen/openldap/
PATCHFILES=	ldapvi_sasl_${PORTVERSION}.diff
PATCH_DIST_STRIP=	-p1
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${PREFIX}/man/man1

.include <bsd.port.post.mk>
