# ex:ts=8
# Ports collection makefile for:	shishi
# Date created:			Oct 19, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	shishi
PORTVERSION=	0.0.14
CATEGORIES=	security
MASTER_SITES=	http://josefsson.org/${PORTNAME}/releases/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A free implementation of the Kerberos 5 network security system

LIB_DEPENDS=	intl.5:${PORTSDIR}/devel/gettext-old \
		idn.12:${PORTSDIR}/devel/libidn \
		tasn1.2:${PORTSDIR}/security/libtasn1

USE_PERL5_BUILD=	yes
USE_GNOME=	gnomehack gnometarget pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		MAKEINFO="makeinfo --no-split"
CONFIGURE_ARGS=	--without-libgcrypt --disable-starttls \
		--with-db-dir=/var/shishi
INSTALLS_SHLIB=	yes

INFO=		shishi

post-extract:
	@${RM} -f ${WRKSRC}/doc/shishi.info*

post-install:
	@${SED} 's:/usr/local:${PREFIX}:g' ${PKGMESSAGE}

.include "Makefile.man"
.include <bsd.port.mk>
