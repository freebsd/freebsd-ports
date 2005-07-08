# New ports collection makefile for:	avenger
# Date created:		8 May 2005
# Whom:			dm
#
# $FreeBSD$
#

PORTNAME=	avenger
PORTVERSION=	0.6.5
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.mailavenger.org/dist/

MAINTAINER=	dm+bugs+avenger@mailavenger.org
COMMENT=	An anti-spam SMTP server

LIB_DEPENDS=	db-4.3:${PORTSDIR}/databases/db43

GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

MAN1=		aliascheck.1 avenger.1 dbutil.1 deliver.1 dotlock.1 \
		edinplace.1 macutil.1 mailexec.1 match.1 smtpdcheck.1 synos.1
MAN5=		asmtpd.conf.5
MAN8=		asmtpd.8 avenger.local.8

AVETC=		${PREFIX}/etc/avenger
CONFIGURE_ENV=	WFLAGS='-Wall'
CONFIGURE_ARGS=	--with-db=${LOCALBASE} --with-etcdir=${AVETC}

post-patch:
	@${FIND} ${WRKSRC}/doc -name "*.[158]" | ${XARGS} \
		${REINPLACE_CMD} -e 's|/etc/avenger|${PREFIX}/etc/avenger|g'

pre-install:
	PKG_PREFIX=${PREFIX} ${SH} pkg-install ${PKGNAME} PRE-INSTALL

post-install:
	PKG_PREFIX=${PREFIX} ${SH} pkg-install ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
