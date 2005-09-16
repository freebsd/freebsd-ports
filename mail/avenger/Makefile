# New ports collection makefile for:	avenger
# Date created:		8 May 2005
# Whom:			dm
#
# $FreeBSD$
#

PORTNAME=	avenger
PORTVERSION=	0.7
CATEGORIES=	mail
MASTER_SITES=	http://www.mailavenger.org/dist/

MAINTAINER=	dm+bugs+avenger@mailavenger.org
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

pre-install:
	PKG_PREFIX=${PREFIX} ${SH} pkg-install ${PKGNAME} PRE-INSTALL

post-install:
	PKG_PREFIX=${PREFIX} ${SH} pkg-install ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
