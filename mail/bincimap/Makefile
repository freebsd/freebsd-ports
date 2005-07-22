# New ports collection makefile for:	bincimap
# Date created:		27 Mar 2003
# Whom:			Sergei Kolobov <sergei@kolobov.com>
#
# $FreeBSD$
#

# The following compile-time options are available:
#
# WITHOUT_OPENSSL	Disable OpenSSL support (enabled by default)
#

PORTNAME=	bincimap
PORTVERSION=	1.2.13
CATEGORIES=	mail
MASTER_SITES=	http://www.bincimap.org/%SUBDIR%/ \
		http://www.bincimap.andreas.hanssen.name/%SUBDIR%/ \
		http://bincimap.argonsoft.de/www.bincimap.org/%SUBDIR%/
MASTER_SITE_SUBDIR=	dl/tarballs/1.2
DISTNAME=	${PORTNAME}-${PORTVERSION}final

MAINTAINER=	sergei@FreeBSD.org
COMMENT=	Light-weight IMAP server for Maildir

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--sysconfdir=${CONFDIR}
CONFDIR=	${PREFIX}/etc/${PORTNAME}

.if defined(WITHOUT_OPENSSL)
CONFIGURE_ARGS+=	--without-ssl
.else
CONFIGURE_ARGS+=	--with-ssl
USE_OPENSSL=		yes
.endif

MAN1=		bincimap-up.1 bincimapd.1
MAN5=		bincimap.conf.5
DOCS=		AUTHORS ChangeLog README doc/bincimap* \
		doc/manual/bincimap-manual.ps
EXAMPLES=	conf/bincimap.conf conf/checkpassword.pl conf/toimapdir \
		conf/tomaildir++ conf/xinetd-bincimap conf/xinetd-bincimaps
CONTRIB=	contrib/README contrib/authenticators/bincimap-auth-teapop.sh

post-install:
	@${MKDIR} ${CONFDIR}
	${INSTALL_DATA} ${WRKSRC}/conf/bincimap.conf \
		${CONFDIR}/bincimap.conf.sample
	@${MKDIR} ${EXAMPLESDIR}/contrib
	cd ${WRKSRC} && ${INSTALL_DATA} ${EXAMPLES} ${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${CONTRIB} ${EXAMPLESDIR}/contrib
	cd ${WRKSRC}/man && ${INSTALL_MAN} ${MAN1} ${MANPREFIX}/man/man1
	cd ${WRKSRC}/man && ${INSTALL_MAN} ${MAN5} ${MANPREFIX}/man/man5
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
