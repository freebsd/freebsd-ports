# Created by: Paul Dlug <paul@nerdlabs.com>
# $FreeBSD$

PORTNAME=	nsca
PORTVERSION=	2.9.1
PORTREVISION=	2
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/nagios/nsca-2.x/nsca-${PORTVERSION}

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Nagios Service Check Acceptor

LICENSE=	GPLv2

#.if !defined(_BUILDING_NSCA_CLIENT)
#RUN_DEPENDS=	nagios:${PORTSDIR}/net-mgmt/nagios
#.endif
LIB_DEPENDS=	mcrypt:${PORTSDIR}/security/libmcrypt

.if !defined(_BUILDING_NSCA_CLIENT)
CONFLICTS=	nsca-2.7.* nsca27-*
.else
PKGNAMESUFFIX=	-client
CONFLICTS=	nsca-client-2.7.* nsca27-*
.endif

GNU_CONFIGURE=	yes
USES=		perl5
CONFIGURE_ARGS=	--prefix=${PREFIX} --localstatedir=/var/spool/nagios
DOCSDIR?=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}

.if !defined(_BUILDING_NSCA_CLIENT)
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

.if defined(_BUILDING_NSCA_CLIENT)
PLIST_SUB+=	CLIENT=""
.else
PLIST_SUB+=	CLIENT="@comment "
.endif

DOCS=		Changelog LEGAL README SECURITY

NO_STAGE=	yes
do-install:
.if defined(_BUILDING_NSCA_CLIENT)
	${INSTALL_PROGRAM} ${WRKSRC}/src/send_nsca ${PREFIX}/sbin/send_nsca
	${MKDIR} ${PREFIX}/etc/nagios
	${INSTALL_DATA} ${WRKSRC}/sample-config/send_nsca.cfg ${PREFIX}/etc/nagios/send_nsca.cfg-sample
.else
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
