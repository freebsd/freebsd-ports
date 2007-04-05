# New ports collection makefile for:	nsca
# Date created:		2003-11-18
# Whom:			Paul Dlug <paul@nerdlabs.com>
#
# $FreeBSD$
#

PORTNAME=	nsca
PORTVERSION=	2.7.1
CATEGORIES=	net-mgmt
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	nagios

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Nagios Service Check Acceptor

.if !defined(WITHOUT_SERVER)
RUN_DEPENDS=	nagios:${PORTSDIR}/net-mgmt/nagios
.endif
LIB_DEPENDS=	mcrypt.8:${PORTSDIR}/security/libmcrypt

GNU_CONFIGURE=	yes
USE_PERL5=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --localstatedir=/var/spool/nagios

.if !defined(WITHOUT_SERVER)
USE_RC_SUBR=	nsca
PLIST_SUB+=	SERVER=""
.else
PLIST_SUB+=	SERVER="@comment "
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
	${INSTALL_DATA} ${WRKSRC}/sample-config/send_nsca.cfg ${PREFIX}/etc/send_nsca.cfg-sample
.endif
.if !defined(WITHOUT_SERVER)
	${INSTALL_PROGRAM} ${WRKSRC}/src/nsca ${PREFIX}/sbin/nsca
	${INSTALL_DATA} ${WRKSRC}/sample-config/nsca.cfg ${PREFIX}/etc/nsca.cfg-sample
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.pre.mk>
.if ${OSVERSION} < 500000
BROKEN=	does not build on 4.x
.endif
.include <bsd.port.post.mk>
