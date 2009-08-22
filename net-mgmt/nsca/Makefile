# New ports collection makefile for:	nsca
# Date created:		2003-11-18
# Whom:			Paul Dlug <paul@nerdlabs.com>
#
# $FreeBSD$
#

PORTNAME=	nsca
PORTVERSION=	2.7.2
PORTREVISION=	2
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/nagios/nsca-2.x/nsca-${PORTVERSION}

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Nagios Service Check Acceptor

.if !defined(WITHOUT_SERVER)
RUN_DEPENDS=	nagios:${PORTSDIR}/net-mgmt/nagios
.endif
LIB_DEPENDS=	mcrypt.8:${PORTSDIR}/security/libmcrypt

.if defined(WITHOUT_SERVER) && defined(WITHOUT_CLIENT)
IGNORE=		you cannot define WITHOUT_SERVER and WITHOUT_CLIENT
.endif

GNU_CONFIGURE=	yes
USE_PERL5=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --localstatedir=/var/spool/nagios
DOCSDIR?=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}

.if !defined(WITHOUT_SERVER)
USE_RC_SUBR=	nsca
PLIST_SUB+=	SERVER=""
WITHOUT_CLIENT=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES+=	pkg-message
.else
PLIST_SUB+=	SERVER="@comment "
PKGMESSAGE=	${WRKDIR}/pkg-message.client
SUB_FILES+=	pkg-message.client
.endif

.if !defined(WITHOUT_CLIENT)
PLIST_SUB+=	CLIENT=""
.else
PLIST_SUB+=	CLIENT="@comment "
.endif

DOCS=		Changelog LEGAL README SECURITY

do-install:
.if !defined(WITHOUT_CLIENT)
	${INSTALL_PROGRAM} ${WRKSRC}/src/send_nsca ${PREFIX}/sbin/send_nsca
	${MKDIR} ${PREFIX}/etc/nagios
	${INSTALL_DATA} ${WRKSRC}/sample-config/send_nsca.cfg ${PREFIX}/etc/nagios/send_nsca.cfg-sample
.endif
.if !defined(WITHOUT_SERVER)
	${INSTALL_PROGRAM} ${WRKSRC}/src/nsca ${PREFIX}/sbin/nsca
	${MKDIR} ${PREFIX}/etc/nagios
	${INSTALL_DATA} ${WRKSRC}/sample-config/nsca.cfg ${PREFIX}/etc/nagios/nsca.cfg-sample
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
