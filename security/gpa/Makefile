# Created by: Clive Lin <clive@CirX.ORG>
# $FreeBSD$

PORTNAME=	gpa
PORTVERSION=	0.9.4
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNUPG}
MASTER_SITE_SUBDIR=	gpa

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	GTK2+ frontend for the GNU Privacy Guard

LICENSE=	GPLv3

LIB_DEPENDS=	libassuan.so:${PORTSDIR}/security/libassuan \
		libgpgme.so:${PORTSDIR}/security/gpgme
BUILD_DEPENDS=	gpgv2:${PORTSDIR}/security/gnupg
RUN_DEPENDS=	gpgv2:${PORTSDIR}/security/gnupg

USES=		gmake pkgconfig
USE_BZIP2=	yes
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	GPGKEYS_LDAP="${LOCALBASE}/libexec/gpg2keys_ldap" \
		GPG="${LOCALBASE}/bin/gpg2"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.options.mk>

.if !exists(${LOCALBASE}/bin/gpgsm)
IGNORE=		requires gpgsm. (Re)Install security/gnupg with the GPGSM option ON, then rebuild security/gpgme if installed
.endif

.include <bsd.port.mk>
