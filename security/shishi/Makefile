# ex:ts=8
# Ports collection makefile for:	shishi
# Date created:			Oct 19, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	shishi
PORTVERSION=	0.0.16
CATEGORIES=	security
MASTER_SITES=	http://josefsson.org/${PORTNAME}/releases/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A free implementation of the Kerberos 5 network security system

LIB_DEPENDS=	idn.15:${PORTSDIR}/devel/libidn \
		gcrypt.12:${PORTSDIR}/security/libgcrypt \
		tasn1.2:${PORTSDIR}/security/libtasn1

PKGMESSAGE=	${WRKDIR}/pkg-message

USE_PERL5_BUILD=	yes
USE_GNOME=	gnomehack gnometarget pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		MAKEINFO="makeinfo --no-split"
CONFIGURE_ARGS=	--disable-starttls \
		--with-db-dir=/var/shishi
INSTALLS_SHLIB=	yes

INFO=		shishi

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

post-extract:
	@${RM} -f ${WRKSRC}/doc/shishi.info*

post-patch:
	@${SED} -e 's,%%PREFIX%%,${PREFIX},g' \
		${FILESDIR}/pkg-message.in > ${PKGMESSAGE}

post-install:
	@${CAT} ${PKGMESSAGE}

.include "Makefile.man"
.include <bsd.port.mk>
