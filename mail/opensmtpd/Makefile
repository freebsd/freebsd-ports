# New ports collection makefile for:	opensmtpd
# Date created:		2012-05-13
# Whom:			Ashish SHUKLA <ashish@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	opensmtpd
PORTVERSION=	201207311144
CATEGORIES=	mail
MASTER_SITES=	http://www.opensmtpd.org/archives/ \
		http://distfiles.pirateparty.in/ashish/

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	OpenSMTPD is a free MTA

LIB_DEPENDS=	event-1.4:${PORTSDIR}/devel/libevent

LICENSE_NAME=	ISCL

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_AUTOTOOLS=	autoconf:env automake:env libtool:env
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libevent-dir=${LOCALBASE}

USE_RC_SUBR=	smtpd
SUB_FILES=	pkg-install pkg-deinstall

CONFLICTS=	postfix-[0-9]* sendmail-[0-9]*

MAN8=		makemap.8 newaliases.8 smtpctl.8 smtpd.8
MAN5=		smtpd.conf.5

USERS=		_smtpd
GROUPS=		_smtpd

.include <bsd.port.options.mk>

USE_OPENSSL=	yes

# FreeBSD 7.3 and earlier need to use OpenSSL from ports
.if ${OSVERSION} < 704000
WITH_OPENSSL_PORT=	yes
.endif

pre-configure:
		@cd ${WRKSRC} && ./bootstrap

post-install:
		@${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

post-deinstall:
		@${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-DEINSTALL

.include <bsd.port.mk>
