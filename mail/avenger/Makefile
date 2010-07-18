# New ports collection makefile for:	avenger
# Date created:		8 May 2005
# Whom:			dm
#
# $FreeBSD$
#
# If you would like to use SASL authentication, you will need to define:
#
#     WITH_AVENGER_SASL2=yes
#
# in your make.conf file.
#

PORTNAME=	avenger
PORTVERSION=	0.8.1
CATEGORIES=	mail
MASTER_SITES=	http://www.mailavenger.org/dist/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An anti-spam SMTP server

LIB_DEPENDS=	db-4.3:${PORTSDIR}/databases/db43

GNU_CONFIGURE=	yes

MAN1=		aliascheck.1 avenger.1 dbutil.1 deliver.1 dotlock.1 \
		edinplace.1 escape.1 macutil.1 mailexec.1 match.1 \
		smtpdcheck.1 synos.1
MAN5=		asmtpd.conf.5
MAN8=		asmtpd.8 avenger.local.8

CONFIGURE_ENV=	WFLAGS='-Wall'
CONFIGURE_ARGS=	--with-db=${LOCALBASE}

.if defined(WITH_AVENGER_SASL2)
LIB_DEPENDS+=	sasl2.2:${PORTSDIR}/security/cyrus-sasl2
# Note, for version 0.7.2, the --enable-sasl=/... syntax is broken
#CONFIGURE_ARGS+=	--enable-sasl=${LOCALBASE}
CONFIGURE_ARGS+=	--enable-sasl
.endif

pre-install:
	PKG_PREFIX=${PREFIX} ${SH} pkg-install ${PKGNAME} PRE-INSTALL

post-install:
	PKG_PREFIX=${PREFIX} ${SH} pkg-install ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
