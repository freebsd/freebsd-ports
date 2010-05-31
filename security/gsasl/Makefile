# ex:ts=8
# Ports collection makefile for:	gsasl
# Date created:			Oct 18, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gsasl
PORTVERSION=	1.4.0
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	krion@FreeBSD.org
COMMENT=	GNU SASL Library

LIB_DEPENDS=	idn.16:${PORTSDIR}/dns/libidn \
		gcrypt.16:${PORTSDIR}/security/libgcrypt \
		ntlm.0:${PORTSDIR}/security/libntlm

USE_GNOME=	gnomehack gnometarget pkgconfig
USE_PERL5_BUILD=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
USE_LDCONFIG=	yes

INFO=	gsasl

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

post-patch:
.for file in \
	lib/po/LINGUAS \
	po/LINGUAS
	@${REINPLACE_CMD} -e '1,2d' ${WRKSRC}/${file}
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
