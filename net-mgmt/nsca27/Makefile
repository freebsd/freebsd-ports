# Created by: Paul Dlug <paul@nerdlabs.com>
# $FreeBSD$

PORTNAME=	nsca
PORTVERSION=	2.7.2
PORTREVISION=	8
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/nagios/nsca-2.x/nsca-${PORTVERSION}

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Nagios Service Check Acceptor

LICENSE=	GPLv2+

#.if !defined(_BUILDING_NSCA_CLIENT)
#RUN_DEPENDS=	nagios:net-mgmt/nagios
#.endif
LIB_DEPENDS=	libmcrypt.so:security/libmcrypt

.if !defined(_BUILDING_NSCA_CLIENT)
PKGNAMESUFFIX=	27
CONFLICTS=	nsca-2.9.*
.else
PKGNAMESUFFIX=	27-client
CONFLICTS=	nsca-client-2.9.*
.endif

GNU_CONFIGURE=	yes
USES=		perl5
CONFIGURE_ARGS=	--prefix=${PREFIX} --localstatedir=/var/spool/nagios
DOCSDIR?=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}

OPTIONS_DEFINE=	DOCS

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

do-install:
.if defined(_BUILDING_NSCA_CLIENT)
	${INSTALL_PROGRAM} ${WRKSRC}/src/send_nsca ${STAGEDIR}${PREFIX}/sbin/send_nsca
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/nagios
	${INSTALL_DATA} ${WRKSRC}/sample-config/send_nsca.cfg ${STAGEDIR}${PREFIX}/etc/nagios/send_nsca.cfg-sample
.else
	${INSTALL_PROGRAM} ${WRKSRC}/src/nsca ${STAGEDIR}${PREFIX}/sbin/nsca
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/nagios
	${INSTALL_DATA} ${WRKSRC}/sample-config/nsca.cfg ${STAGEDIR}${PREFIX}/etc/nagios/nsca.cfg-sample
.endif

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
