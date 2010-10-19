# New ports collection makefile for:	spamdyke
# Date created:		11 January 2007
# Whom:			Peter Kieser <peter@kieser.ca>
#
# $FreeBSD$
#

PORTNAME=	spamdyke
PORTVERSION=	4.1.0
CATEGORIES=	mail
MASTER_SITES=	http://www.spamdyke.org/releases/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A filter for monitoring and intercepting SMTP connections on qmail

RUN_DEPENDS=	${LOCALBASE}/bin/tcprules:${PORTSDIR}/sysutils/ucspi-tcp

WRKSRC=		${WRKDIR}/${DISTNAME}/spamdyke

USE_QMAIL=	yes
GNU_CONFIGURE=	yes

ALL_TARGET=	spamdyke

OPTIONS=	TLS "Enable TLS support" On \
		DEBUG "Enable debugging output" Off \
		DEBUG_EXCESSIVE "Enable excessive debugging output" Off

.include <bsd.port.pre.mk>
.if ${OSVERSION} <= 700042
BROKEN=	this port causes gcc to segfault
.endif

.if defined(WITHOUT_TLS)
CONFIGURE_ARGS+=	--disable-tls
.else
CONFIGURE_ARGS+=	--enable-tls
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--with-debug-output
.else
CONFIGURE_ARGS+=	--without-debug-output
.endif

.if defined(WITH_DEBUG_EXCESSIVE)
CONFIGURE_ARGS+=	--with-excessive-output
.else
CONFIGURE_ARGS+=	--without-excessive-output
.endif

.if !defined(NOPORTDOCS)
PORTDOCS=	Changelog.txt FAQ.html GNUGPL.txt INSTALL.txt \
		README.html README_ip_file_format.html \
		README_rdns_directory_format.html README_rdns_file_format.html \
		UPGRADING.txt UPGRADING_version_3_to_version_4.txt
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKDIR}/${DISTNAME}/documentation && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/documentation/spamdyke.conf.example ${PREFIX}/etc
	@if [ ! -f ${PREFIX}/etc/spamdyke.conf ]; then \
		${CP} -p ${PREFIX}/etc/spamdyke.conf.example ${PREFIX}/etc/spamdyke.conf; \
	fi

post-patch:
	@${REINPLACE_CMD} -e 's#^CFLAGS :=.*#CFLAGS = ${CFLAGS}#' ${WRKSRC}/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/spamdyke ${PREFIX}/bin

.include <bsd.port.post.mk>
