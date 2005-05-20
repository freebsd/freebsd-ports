# New ports collection makefile for:	avenger
# Date created:		8 May 2005
# Whom:			dm
#
# $FreeBSD$
#

PORTNAME=	avenger
PORTVERSION=	0.6.2
CATEGORIES=	mail
MASTER_SITES=	http://www.mailavenger.org/dist/

MAINTAINER=	dm+bug+avenger@mailavenger.org
COMMENT=	An anti-spam SMTP server

LIB_DEPENDS=	db-4.3:${PORTSDIR}/databases/db43

GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

MAN1=		aliascheck.1 avenger.1 dbutil.1 deliver.1 dotlock.1 \
		edinplace.1 macutil.1 mailexec.1 match.1 smtpdcheck.1 synos.1
MAN5=		asmtpd.conf.5
MAN8=		asmtpd.8 avenger.local.8

CONFIGURE_ARGS=	--with-db=${LOCALBASE}

post-patch:
	@${FIND} ${WRKSRC} -type f -exec ${REINPLACE_CMD} -e \
		's|\(/etc/avenger\)|${PREFIX}\1|g' {} \;
	@${REINPLACE_CMD} -e 's|-Werror||' ${WRKSRC}/configure

pre-install:
	PKG_PREFIX=${PREFIX} ${SH} pkg-install ${PKGNAME} PRE-INSTALL

post-install:
	PKG_PREFIX=${PREFIX} ${SH} pkg-install ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
