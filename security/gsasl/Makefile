# Created by: ijliao
# $FreeBSD$

PORTNAME=	gsasl
PORTVERSION=	1.8.0
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	GNU SASL Library

LIB_DEPENDS=	idn.17:${PORTSDIR}/dns/libidn \
		gcrypt:${PORTSDIR}/security/libgcrypt \
		gnutls.26:${PORTSDIR}/security/gnutls \
		ntlm.0:${PORTSDIR}/security/libntlm

USES=		charsetfix pathfix perl5 pkgconfig
USE_PERL5=	build
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

INFO=	gsasl

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
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
