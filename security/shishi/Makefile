# ex:ts=8
# Ports collection makefile for:	shishi
# Date created:			Oct 19, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	shishi
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	GNU

MAINTAINER=	johans@FreeBSD.org
COMMENT=	A free implementation of the Kerberos 5 network security system

LIB_DEPENDS=	idn.16:${PORTSDIR}/dns/libidn \
		tasn1.4:${PORTSDIR}/security/libtasn1 \
		gcrypt.16:${PORTSDIR}/security/libgcrypt \
		gnutls.40:${PORTSDIR}/security/gnutls

USE_AUTOTOOLS=	libtool:22
USE_PERL5_BUILD=	yes
USE_GNOME=	gnomehack gnometarget pkgconfig
USE_ICONV=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}" \
		MAKEINFO="makeinfo --no-split"
CONFIGURE_ARGS=	--with-db-dir=/var/shishi
USE_LDCONFIG=	yes

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

.if ${OSVERSION} < 800000
CONFIGURE_ARGS+=	gl_cv_func_stat_dir_slash="guessing yes" \
			gl_cv_func_stat_file_slash="guessing yes"
.endif

post-extract:
	@${RM} -f ${WRKSRC}/doc/shishi.info*
	@cd ${WRKSRC}/db/gl && ${LN} -s ../../build-aux/link-warning.h

post-patch:
	@${REINPLACE_CMD} -e 's/$$(LINK_WARNING_H)/link-warning.h/' \
		${WRKSRC}/db/gl/Makefile.in
	@${REINPLACE_CMD} -e 's:\.\./gl/libgnu.la:../db/gl/libgnu.la &:' \
		${WRKSRC}/src/Makefile.in

.include <bsd.port.post.mk>
