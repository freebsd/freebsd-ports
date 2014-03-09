# Created by: barner
# $FreeBSD$

PORTNAME=	fprint_demo
PORTVERSION=	20080303
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_DEBIAN}
MASTER_SITE_SUBDIR=	pool/main/f/${PORTNAME:C/_/-/}
DISTNAME=	${PORTNAME:C/_/-/}_${PORTVERSION}git.orig

MAINTAINER=	lichray@gmail.com
COMMENT=	Demo and test application for libfprint

LIB_DEPENDS=	fprint:${PORTSDIR}/security/libfprint

USE_AUTOTOOLS=	autoconf automake
AUTOMAKE_ARGS=	-a
GNU_CONFIGURE=	yes
USES=		pkgconfig
USE_GNOME=	atk glib20 gtk20 pango
INSTALLS_ICONS=	yes

WRKSRC=	${WRKDIR}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800069
IGNORE=		libfprint will not compile on FreeBSD < 8
.endif

CONFIGURE_ENV+=	CRYPTO_CFLAGS=-I${OPENSSLINC} \
		CRYPTO_LIBS=-lcrypto
CFLAGS+=	-DHAVE_MEMMEM

pre-configure:
	cd ${WRKDIR} && ${ACLOCAL}

post-install:
	@-update-desktop-database
	@${ECHO}
	@${ECHO} =========================================================================
	@${ECHO}
	@${CAT} ${PKGMESSAGE}
	@${ECHO}
	@${ECHO} =========================================================================
	@${ECHO}

.include <bsd.port.post.mk>
