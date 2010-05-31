# New ports collection makefile for:	libgpg-error
# Date created:		2003-10-12
# Whom:			Sergei Kolobov <sergei@kolobov.com>
#
# $FreeBSD$
#

PORTNAME=	libgpg-error
PORTVERSION=	1.7
PORTREVISION=	1
CATEGORIES=	security devel
MASTER_SITES=	${MASTER_SITE_GNUPG}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Common error values for all GnuPG components

USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool:22
USE_GNOME=	ltverhack
USE_LDCONFIG=		yes
GNU_CONFIGURE=		yes
MAKE_JOBS_UNSAFE=	yes

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS=	--disable-nls
PLIST_SUB=	NLS="@comment "
.else
USE_ICONV=	yes
USE_GETTEXT=	yes
CONFIGURE_ARGS=	--with-libiconv-prefix=${LOCALBASE} \
		--with-libintl-prefix=${LOCALBASE}
PLIST_SUB=	NLS=""
.endif

DOCS=		AUTHORS ChangeLog NEWS README

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
