# New ports collection makefile for:	gpa
# Date created:		16 August 2000
# Whom:			Clive Lin <clive@CirX.ORG>
#
# $FreeBSD$
#

PORTNAME=	gpa
PORTVERSION=	0.9.2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNUPG}
MASTER_SITE_SUBDIR=	gpa

MAINTAINER=	bsdkaffee@gmail.com
COMMENT=	A graphical frontend for the GNU Privacy Guard

LICENSE=	GPLv3

LIB_DEPENDS=	assuan.0:${PORTSDIR}/security/libassuan \
		gpgme.19:${PORTSDIR}/security/gpgme
BUILD_DEPENDS=	gpgv2:${PORTSDIR}/security/gnupg
RUN_DEPENDS=	gpgv2:${PORTSDIR}/security/gnupg

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	GPGKEYS_LDAP="${LOCALBASE}/libexec/gpg2keys_ldap"
MAKE_JOBS_SAFE=	yes

MAN1=		gpa.1

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
