# New ports collection makefile for:	bincimap
# Date created:		27 Mar 2003
# Whom:			Sergei Kolobov <sergei@kolobov.com>
#
# $FreeBSD$
#

# The following compile-time options are available:
#
# WITH_XINETD		Use xinetd instead of the default daemontools/ucspi-tcp
# WITHOUT_OPENSSL	Disable OpenSSL support (enabled by default)
#

PORTNAME=	bincimap
PORTVERSION=	1.2.3
CATEGORIES=	mail
MASTER_SITES=	http://www.bincimap.org/%SUBDIR%/ \
		http://www.bincimap.andreas.hanssen.name/%SUBDIR%/ \
		http://bincimap.argonsoft.de/www.bincimap.org/%SUBDIR%/
MASTER_SITE_SUBDIR=	dl/tarballs/1.2

PATCH_SITES=	${MASTER_SITES:S!%SUBDIR%!${MASTER_SITE_SUBDIR}!}
#PATCHFILES=	bincimap-1.2.1-patch000-mimeparser

MAINTAINER=	sergei@FreeBSD.org
COMMENT=	Light-weight IMAP server for Maildir

.if defined(WITH_XINETD)
RUN_DEPENDS=	xinetd:${PORTSDIR}/security/xinetd
PLIST_SUB+=	XINETD="" DJB="@comment "
.else
RUN_DEPENDS=	supervise:${PORTSDIR}/sysutils/daemontools \
		tcpserver:${PORTSDIR}/sysutils/ucspi-tcp
PLIST_SUB+=	XINETD="@comment " DJB=""
.endif

USE_BZIP2=	yes
GNU_CONFIGURE=	yes

CONFDIR=		${PREFIX}/etc/${PORTNAME}
CONFIGURE_ARGS+=	--sysconfdir=${CONFDIR}
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

.if defined(WITHOUT_OPENSSL)
CONFIGURE_ARGS+=	--without-ssl
PLIST_SUB+=		SSL="@comment "
.else
CONFIGURE_ARGS+=	--with-ssl
USE_OPENSSL=		yes
PLIST_SUB+=		SSL=""
.endif

MAN1=		bincimap-up.1 bincimapd.1
MAN5=		bincimap.conf.5
DOCS=		AUTHORS ChangeLog README doc/bincimap* \
		doc/manual/bincimap-manual.ps
EXAMPLES=	contrib/README contrib/authenticators/bincimap-auth-teapop.sh

post-install:
	@${MKDIR} ${CONFDIR}
	${INSTALL_DATA} ${WRKSRC}/conf/bincimap.conf \
		${CONFDIR}/bincimap.conf.sample
.if defined(WITH_XINETD)
	${INSTALL_DATA} ${WRKSRC}/conf/xinetd-bincimap ${CONFDIR}/imap.sample
.if !defined(WITHOUT_OPENSSL)
	${INSTALL_DATA} ${WRKSRC}/conf/xinetd-bincimaps ${CONFDIR}/imaps.sample
.endif
.else
	@${MKDIR} ${CONFDIR}/imap.sample
	${INSTALL_SCRIPT} ${WRKSRC}/service/run ${CONFDIR}/imap.sample
	@${MKDIR} ${CONFDIR}/imap.sample/log
	${INSTALL_SCRIPT} ${WRKSRC}/service/log/run ${CONFDIR}/imap.sample/log
.if !defined(WITHOUT_OPENSSL)
	@${MKDIR} ${CONFDIR}/imaps.sample
	${INSTALL_SCRIPT} ${WRKSRC}/service/run-ssl ${CONFDIR}/imaps.sample/run
	@${MKDIR} ${CONFDIR}/imaps.sample/log
	${INSTALL_SCRIPT} ${WRKSRC}/service/log/run ${CONFDIR}/imaps.sample/log
.endif
.endif
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${EXAMPLES} ${EXAMPLESDIR}
	cd ${WRKSRC}/man && ${INSTALL_MAN} ${MAN1} ${MANPREFIX}/man/man1
	cd ${WRKSRC}/man && ${INSTALL_MAN} ${MAN5} ${MANPREFIX}/man/man5
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
