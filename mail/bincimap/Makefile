# New ports collection makefile for:	bincimap
# Date created:		27 Mar 2003
# Whom:			Sergei Kolobov <sergei@kolobov.com>
#
# $FreeBSD$
#

PORTNAME=	bincimap
PORTVERSION=	1.1.5
CATEGORIES=	mail
MASTER_SITES=	http://www.bincimap.org/dl/tarballs/

MAINTAINER=	sergei@kolobov.com
COMMENT=	Light-weight IMAP server for Maildir

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GETOPT_LONG=	yes

CONFDIR?=	${PREFIX}/etc/${PORTNAME}
PLIST_SUB+=	CONFDIR="${CONFDIR:S,^${PREFIX}/,,}"

CONFIGURE_ARGS+=	--sysconfdir=${CONFDIR}
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

.if defined(WITHOUT_OPENSSL)
CONFIGURE_ARGS+=	--without-ssl
.else
CONFIGURE_ARGS+=	--with-ssl
USE_OPENSSL=	yes
.endif

MAN1=		bincimap-up.1 bincimapd.1
MAN5=		bincimap.conf.5
DOCS=		AUTHORS ChangeLog README doc/bincimap*

post-install:
	@${MKDIR} ${CONFDIR}
	${INSTALL_DATA} ${WRKSRC}/conf/bincimap.conf \
		${CONFDIR}/bincimap.conf.sample
	@${MKDIR} ${EXAMPLESDIR}
.for dir in xinetd supervise/imap/log supervise/imaps/log
	@${MKDIR} ${EXAMPLESDIR}/${dir}
.endfor
	@cd ${WRKSRC}/conf && \
	    ${INSTALL_DATA} xinetd-bincimap ${EXAMPLESDIR}/xinetd/imap && \
	    ${INSTALL_DATA} xinetd-bincimaps ${EXAMPLESDIR}/xinetd/imaps
	@cd ${WRKSRC}/service && \
	    ${INSTALL_DATA} run ${EXAMPLESDIR}/supervise/imap && \
	    ${INSTALL_DATA} log/run ${EXAMPLESDIR}/supervise/imap/log && \
	    ${INSTALL_DATA} run-ssl ${EXAMPLESDIR}/supervise/imaps/run && \
	    ${INSTALL_DATA} log/run ${EXAMPLESDIR}/supervise/imaps/log
	cd ${WRKSRC}/man && ${INSTALL_MAN} ${MAN1} ${MANPREFIX}/man/man1
	cd ${WRKSRC}/man && ${INSTALL_MAN} ${MAN5} ${MANPREFIX}/man/man5
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
