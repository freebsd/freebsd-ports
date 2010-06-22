# New ports collection makefile for:	gpa
# Date created:		16 August 2000
# Whom:			Clive Lin <clive@CirX.ORG>
#
# $FreeBSD$
#

PORTNAME=	gpa
PORTVERSION=	0.9.0
PORTREVISION=	6
CATEGORIES=	security
MASTER_SITES=	http://wald.intevation.org/frs/download.php/603/

MAINTAINER=	bsdkaffee@gmail.com
COMMENT=	A graphical frontend for the GNU Privacy Guard

LIB_DEPENDS=	assuan.0:${PORTSDIR}/security/libassuan \
		gpgme.18:${PORTSDIR}/security/gpgme
BUILD_DEPENDS=	gpgv2:${PORTSDIR}/security/gnupg
RUN_DEPENDS=	gpgv2:${PORTSDIR}/security/gnupg

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LIBS="-L${LOCALBASE}/lib" \
		GPGKEYS_LDAP="${LOCALBASE}/libexec/gpg2keys_ldap"
MAKE_JOBS_SAFE=	yes

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS=	NLS "Native language support" on

.include <bsd.port.pre.mk>

.if !exists(${LOCALBASE}/bin/gpgsm)
IGNORE=		requires gpgsm. (Re)Install security/gnupg with the GPGSM option ON, then rebuild security/gpgme if installed
.endif

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

.include <bsd.port.post.mk>
