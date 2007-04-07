# New ports collection makefile for:	nrpe
# Date created:				1 Aug 2002
# Whom:					Paul Dlug<paul@nerdlabs.com>
#
# $FreeBSD$
#

PORTNAME=	nrpe2
PORTVERSION=	2.7
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	nagios
DISTNAME=	nrpe-${PORTVERSION}

MAINTAINER=	dan@langille.org
COMMENT=	Nagios Remote Plugin Executor

RUN_DEPENDS=	${LOCALBASE}/libexec/nagios/check_nagios:${PORTSDIR}/net-mgmt/nagios-plugins

GNU_CONFIGURE=	yes
USE_PERL5_BUILD=	yes

USE_RC_SUBR=	nrpe2.sh
SUB_FILES=	pkg-message

PLIST_FILES=	sbin/nrpe2 etc/nrpe.cfg-sample libexec/nagios/check_nrpe2

CONFIGURE_ARGS=	--libexecdir=${PREFIX}/libexec/nagios \
		--bindir=${PREFIX}/sbin --sysconfdir=${PREFIX}/etc

OPTIONS=	SSL "SSL support" off \
		ARGS "Enable command arguments *POTENTIAL SECURITY RISK*" off

.include <bsd.port.pre.mk>

.if defined(WITH_SSL)
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
CONFIGURE_ARGS+=	--enable-ssl
.else
CONFIGURE_ARGS+=	--disable-ssl
.endif

.if defined(WITH_ARGS)
CONFIGURE_ARGS+=	--enable-command-args
.endif

post-build:
	@${REINPLACE_CMD} -e 's|nrpe.pid|nrpe2.pid|g' \
		${WRKSRC}/sample-config/nrpe.cfg

pre-install:
	PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/nrpe ${PREFIX}/sbin/nrpe2
	${INSTALL_PROGRAM} ${WRKSRC}/src/check_nrpe \
		${PREFIX}/libexec/nagios/check_nrpe2
	${INSTALL_DATA} ${WRKSRC}/sample-config/nrpe.cfg \
		${PREFIX}/etc/nrpe.cfg-sample

post-install:
	${CAT} ${PKGMESSAGE}

post-deinstall:
	PKG_PREFIX=${PREFIX} ${SH} ${PKGDEINSTALL} ${PKGNAME} DEINSTALL

.include <bsd.port.post.mk>
