PORTNAME=	gpa
PORTVERSION=	0.11.0
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	GNUPG/gpa

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	GTK3+ frontend for the GNU Privacy Guard
WWW=		https://www.gnupg.org/software/gpa/index.html

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gpgv2:security/gnupg
LIB_DEPENDS=	libassuan.so:security/libassuan \
		libgpgme.so:security/gpgme \
		libgpg-error.so:security/libgpg-error
RUN_DEPENDS=	gpgv2:security/gnupg

USES=		desktop-file-utils gmake gnome localbase pkgconfig tar:bzip2
USE_GNOME=	gdkpixbuf gtk30

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	GPGKEYS_LDAP="${LOCALBASE}/libexec/gpg2keys_ldap"
LDFLAGS+=	-Wl,--as-needed

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
