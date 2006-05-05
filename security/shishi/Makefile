# ex:ts=8
# Ports collection makefile for:	shishi
# Date created:			Oct 19, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	shishi
PORTVERSION=	0.0.22
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://josefsson.org/${PORTNAME}/releases/ \
		${MASTER_SITE_GNU_ALPHA}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A free implementation of the Kerberos 5 network security system

LIB_DEPENDS=	idn.16:${PORTSDIR}/dns/libidn \
		tasn1.3:${PORTSDIR}/security/libtasn1

USE_PERL5_BUILD=	yes
USE_GNOME=	gnomehack gnometarget pkgconfig
USE_ICONV=	yes
USE_GETOPT_LONG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}" \
		MAKEINFO="makeinfo --no-split"
CONFIGURE_ARGS=	--disable-starttls \
		--with-db-dir=/var/shishi
INSTALLS_SHLIB=	yes

INFO=		shishi

SUB_FILES=	pkg-message

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.include "Makefile.man"
.include <bsd.port.pre.mk>

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

post-extract:
	@${RM} -f ${WRKSRC}/doc/shishi.info*

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
