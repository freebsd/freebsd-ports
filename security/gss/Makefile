# ex:ts=8
# Ports collection makefile for:	gss
# Date created:			Oct 19, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gss
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	GNU

MAINTAINER=	johans@FreeBSD.org
COMMENT=	GNU Generic Security Service Library

LIB_DEPENDS=	shishi.1:${PORTSDIR}/security/shishi

CONFLICTS=	heimdal-[0-9]*

USE_PERL5_BUILD=	yes
USE_GNOME=	gnomehack gnometarget pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--disable-kerberos5
USE_LDCONFIG=	yes

INFO=		gss
PORTDOCS=	gss.html gss.ps gss.pdf

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.include "Makefile.man"
.include <bsd.port.pre.mk>

.ifdef	WITHOUT_NLS
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=		yes
PLIST_SUB+=	NLS=""
.endif

pre-install:
	@${MKDIR} ${PREFIX}/${INFO_PATH}

post-install:
.ifndef	NOPORTDOCS
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
