# ex:ts=8
# Ports collection makefile for:	gsasl
# Date created:			Oct 18, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gsasl
PORTVERSION=	0.0.8
CATEGORIES=	security
MASTER_SITES=	http://josefsson.org/${PORTNAME}/releases/ \
		ftp://alpha.gnu.org/pub/gnu/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU SASL Library

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig
LIB_DEPENDS=	iconv.3:${PORTSDIR}/converters/libiconv \
		intl.5:${PORTSDIR}/devel/gettext \
		ntlm.0:${PORTSDIR}/security/libntlm \
		gcrypt.6:${PORTSDIR}/security/libgcrypt \
		idn.12:${PORTSDIR}/devel/libidn

USE_GNOME=	gnomehack gnomeprefix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	LDFLAGS="-L${LOCALBASE}/lib"

INSTALLS_SHLIB=	yes

INFO=	gsasl
MAN1=	gsasl.1

post-install:
	@(cd ${WRKSRC}/doc/man ; \
		${LS} *.3 | ${SED} 's,^,man/man3/,' >> ${TMPPLIST})

.include <bsd.port.mk>
