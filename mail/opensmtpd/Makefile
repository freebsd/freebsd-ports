# New ports collection makefile for:	opensmtpd
# Date created:		2012-05-13
# Whom:			Ashish SHUKLA <ashish@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	opensmtpd
PORTVERSION=	5.3.2
PORTEPOCH=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.opensmtpd.org/archives/ \
		http://distfiles.pirateparty.in/ashish/
DISTNAME=	${PORTNAME}-${PORTVERSION}p1

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	OpenSMTPD is a free MTA

LIB_DEPENDS=	event-1:${PORTSDIR}/devel/libevent \
		sqlite3:${PORTSDIR}/databases/sqlite3

LICENSE_NAME=	ISCL

OPTIONS_DEFINE=	PAM

OPTIONS_DEFAULT=	PAM

USE_AUTOTOOLS=	autoconf:env automake:env libtool:env
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libevent-dir=${LOCALBASE}

USE_RC_SUBR=	smtpd
SUB_FILES=	pkg-install pkg-deinstall pkg-message

CONFLICTS_INSTALL=	postfix-[0-9]* sendmail-[0-9]*

MAN8=		makemap.8 newaliases.8 smtpctl.8 smtpd.8
MAN5=		smtpd.conf.5 aliases.5 forward.5

USERS=		_smtpd _smtpq _smtpf
GROUPS=		_smtpd

.include <bsd.port.options.mk>

USE_OPENSSL=	yes

.if ${PORT_OPTIONS:MPAM}
CONFIGURE_ARGS+=	--with-pam
.endif

# FreeBSD 7.3 and earlier need to use OpenSSL from ports
.if ${OSVERSION} < 704000
WITH_OPENSSL_PORT=	yes
.endif

pre-configure:
		@cd ${WRKSRC} && ./bootstrap

post-install:
		@${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
		@${CAT} ${PKGMESSAGE}

post-deinstall:
		@${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-DEINSTALL

.include <bsd.port.mk>
