PORTNAME=	gpa
PORTVERSION=	0.10.0
PORTREVISION=	3
CATEGORIES=	security
MASTER_SITES=	GNUPG/gpa

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	GTK2+ frontend for the GNU Privacy Guard
WWW=		https://gpa.wald.intevation.org/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libassuan.so:security/libassuan \
		libgpgme.so:security/gpgme \
		libgpg-error.so:security/libgpg-error
BUILD_DEPENDS=	gpgv2:security/gnupg
RUN_DEPENDS=	gpgv2:security/gnupg

USES=		desktop-file-utils gmake gnome localbase pkgconfig tar:bzip2
USE_GNOME=	gdkpixbuf2 gtk20

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	GPGKEYS_LDAP="${LOCALBASE}/libexec/gpg2keys_ldap"
LDFLAGS+=	-Wl,--as-needed

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
