# Created by: Mohammad S. Babaei <info@babaei.net>
# $FreeBSD$

PORTNAME=	jwsmtp
PORTVERSION=	1.32.15
CATEGORIES=	mail
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/jwsmtp%20version%201.32.15%20bugfix/

MAINTAINER=	info@babaei.net
COMMENT=	C++ library for sending email

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

NO_OPTIONS_SORT=	yes
OPTIONS_DEFINE=		DOCS MANPAGES
OPTIONS_DEFAULT=	DOCS MANPAGES

DOCS_DESC=	Install documentation
MANPAGES_DESC=	Install manpages

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		libtool pathfix
INSTALL_TARGET=	install-strip

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PLIST_SUB+=	PORTDOCS=""
.else
PLIST_SUB+=	PORTDOCS="@comment "
.endif

.if ${PORT_OPTIONS:MMANPAGES}
PLIST_SUB+=	MANPAGES=""
.else
PLIST_SUB+=	MANPAGES="@comment "
.endif

.include <bsd.port.mk>
