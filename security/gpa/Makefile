# Created by: Clive Lin <clive@CirX.ORG>
# $FreeBSD$

PORTNAME=	gpa
PORTVERSION=	0.9.9
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	GNUPG/gpa

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	GTK2+ frontend for the GNU Privacy Guard

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libassuan.so:security/libassuan \
		libgpgme.so:security/gpgme
BUILD_DEPENDS=	gpgv2:security/gnupg
RUN_DEPENDS=	gpgv2:security/gnupg

USES=		gmake pkgconfig tar:bzip2
USE_GNOME=	gtk20

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	GPGKEYS_LDAP="${LOCALBASE}/libexec/gpg2keys_ldap"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

pre-configure:
	@(if [ ! -e ${LOCALBASE}/bin/gpgsm ] ; then \
	${ECHO_MSG} "gpa requires gpgsm. (Re)Install security/gnupg with the GPGSM option ON" ; \
	exit 1; \
	fi)

.include <bsd.port.mk>
