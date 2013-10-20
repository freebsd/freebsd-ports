# Created by: Clive Lin <clive@CirX.ORG>
# $FreeBSD$

PORTNAME=	gpa
PORTVERSION=	0.9.3
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNUPG}
MASTER_SITE_SUBDIR=	gpa

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	GTK2+ frontend for the GNU Privacy Guard

LICENSE=	GPLv3

LIB_DEPENDS=	assuan:${PORTSDIR}/security/libassuan \
		gpgme:${PORTSDIR}/security/gpgme
BUILD_DEPENDS=	gpgv2:${PORTSDIR}/security/gnupg
RUN_DEPENDS=	gpgv2:${PORTSDIR}/security/gnupg

USES=		pkgconfig
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	GPGKEYS_LDAP="${LOCALBASE}/libexec/gpg2keys_ldap" \
		GPG="${LOCALBASE}/bin/gpgv2"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		gpa.1

OPTIONS_DEFINE=	NLS

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if !exists(${LOCALBASE}/bin/gpgsm)
IGNORE=		requires gpgsm. (Re)Install security/gnupg with the GPGSM option ON, then rebuild security/gpgme if installed
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.mk>
