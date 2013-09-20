# Created by: Joerg Pulz <Joerg.Pulz@frm2.tum.de>
# $FreeBSD$

PORTNAME=	ldapvi
PORTVERSION=	1.7
PORTREVISION=	3
CATEGORIES=	sysutils net
MASTER_SITES=	http://www.lichteblau.com/download/ \
		${MASTER_SITE_LOCAL:S,%SUBDIR%,sbz,}

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	A tool to update LDAP entries with a text editor

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	popt:${PORTSDIR}/devel/popt

USE_OPENLDAP=	yes
USE_GNOME=	glib20
USES=		pkgconfig iconv
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
MAKEFILE=	GNUmakefile

CFLAGS+=	-I${LOCALBASE}/include
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		${PORTNAME}.1
PLIST_FILES=	bin/${PORTNAME} \
		${DOCSDIR_REL}/manual.css ${DOCSDIR_REL}/manual.xml \
		${DOCSDIR_REL}/bg.png ${DOCSDIR_REL}/html.xsl
PLIST_DIRS=	${DOCSDIR_REL}

.if !defined(WANT_OPENLDAP_SASL) || defined(WITHOUT_SASL)
CONFIGURE_ARGS+=--without-sasl
.endif

NO_STAGE=	yes
.include <bsd.port.mk>
