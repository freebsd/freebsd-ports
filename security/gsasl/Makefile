# ex:ts=8
# Ports collection makefile for:	gsasl
# Date created:			Oct 18, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gsasl
PORTVERSION=	1.6.1
PORTREVISION=	3
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	GNU SASL Library

LIB_DEPENDS=	idn.17:${PORTSDIR}/dns/libidn \
		gcrypt.18:${PORTSDIR}/security/libgcrypt \
		gnutls.47:${PORTSDIR}/security/gnutls \
		ntlm.0:${PORTSDIR}/security/libntlm

USE_GNOME=	gnomehack pkgconfig
USE_PERL5_BUILD=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

INFO=	gsasl

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

CPPFLAGS+=	-nostdinc -I/usr/include -I${LOCALBASE}/include
LDFLAGS+=	-L/usr/lib -L${LOCALBASE}/lib

post-patch:
.for file in \
	lib/po/LINGUAS \
	po/LINGUAS
	@${REINPLACE_CMD} -e '/^en@/d' ${WRKSRC}/${file}
.endfor

.include <bsd.port.pre.mk>

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/reference
	${INSTALL_DATA} ${WRKSRC}/doc/reference/html/* ${DOCSDIR}/reference
.endif

.include "Makefile.man"
.include <bsd.port.post.mk>
