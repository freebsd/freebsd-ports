# New ports collection makefile for:	balsa2
# Date created:				19 June 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	balsa2
PORTVERSION=	2.0.18
CATEGORIES=	mail gnome
MASTER_SITES=	http://www.theochem.kth.se/~pawsa/balsa/
DISTNAME=	balsa-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A mail reader for the GNOME 2 desktop

LIB_DEPENDS=	aspell.15:${PORTSDIR}/textproc/aspell \
		pcre.0:${PORTSDIR}/devel/pcre \
		esmtp.6:${PORTSDIR}/mail/libesmtp

USE_GMAKE=	yes
USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_PERL5=	yes
USE_OPENSSL=	yes
USE_GNOME=	gnomeprefix intlhack gnomehack libgnomeui libgnomeprintui \
		libgtkhtml
USE_LIBTOOL_VER=15
USE_LIBLTDL=	yes
USE_ICONV=	yes
CONFIGURE_ARGS=	--enable-threads \
		--enable-gtkhtml \
		--disable-more-warnings \
		--with-ssl \
		--enable-gtkhtml=no
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib -liconv"

MAN1=		balsa.1

CONFLICTS=	balsa-*

OPTIONS=	GPG "Enable GnuPG support" off \
		LDAP "Enable LDAP support" on

.include <bsd.port.pre.mk>

.if defined(WITH_GPG)
LIB_DEPENDS+=		gpgme.9:${PORTSDIR}/security/gpgme
CONFIGURE_ARGS+=	--with-gpgme=${LOCALBASE}/bin/gpgme-config
.endif

.if !defined(WITHOUT_LDAP)
USE_OPENLDAP=		yes
CONFIGURE_ARGS+=	--with-ldap
.endif

.include <bsd.port.post.mk>
