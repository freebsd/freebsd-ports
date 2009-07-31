# New ports collection makefile for:	openconnect
# Date created:				03 June 2009
# Whom:					Damian Gerow
#
# $FreeBSD$
#

PORTNAME=	openconnect
PORTVERSION=	2.00
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.infradead.org/pub/openconnect/ \
		CRITICAL

MAINTAINER=	dgerow@afflictions.org
COMMENT=	A client for Cisco\'s AnyConnect SSL VPN

LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2

USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes
USE_OPENSSL=	yes
OPENSSL=	${OPENSSLBASE}

MAN8=		openconnect.8
PORTDOCS=	README.*

.include <bsd.port.options.mk>

OPTIONS=	GUI      "Enable the OpenConnect configuration GUI"   off

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_GUI)
LIB_DEPENDS+=	gtk-x11-2.0.0:${PORTSDIR}/x11-toolkits/gtk20
LIB_DEPENDS+=	gconf-2.4:${PORTSDIR}/devel/gconf2
PLIST_SUB+=	WITH_GUI=""
.else
PLIST_SUB+=	WITH_GUI="@comment "
.endif

do-install:
	${INSTALL_PROGRAM} -m 751 ${WRKSRC}/openconnect \
	${PREFIX}/bin/openconnect
.if !defined(WITHOUT_GUI)
	${INSTALL_PROGRAM} ${WRKSRC}/nm-openconnect-auth-dialog \
	${PREFIX}/libexec
.endif
	${INSTALL_MAN} ${WRKSRC}/${MAN8} ${MANPREFIX}/man/man8

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README.DTLS ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README.SecurID ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
