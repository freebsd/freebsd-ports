# New ports collection makefile for:	darkstat
# Date created:				24 February 2002
# Whom:					Anders Nordby <anders@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	darkstat
PORTVERSION=	2.6
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://members.optushome.com.au/emikulic/net/darkstat/ \
		http://yallara.cs.rmit.edu.au/~emikulic/_/

MAINTAINER=	emikulic@optushome.com.au
COMMENT=	Network statistics gatherer, similar to ntop

USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS=	--disable-nls
PLIST_SUB=	NLS="@comment "
.else
CONFIGURE_ARGS=	--with-libintl-prefix=${LOCALBASE}
PLIST_SUB=	NLS=""
.endif

MAN1=	darkstat.1
DOCS=	AUTHORS ChangeLog INSTALL ISSUES README

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
