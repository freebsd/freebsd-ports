# New ports collection makefile for:	spamdyke
# Date created:		11 January 2007
# Whom:			Peter Kieser <peter@kieser.ca>
#
# $FreeBSD$
#

PORTNAME=	spamdyke
PORTVERSION=	3.1.7
CATEGORIES=	mail
MASTER_SITES=	http://www.spamdyke.org/releases/
EXTRACT_SUFX=	.tgz

MAINTAINER=	peter@kieser.ca
COMMENT=	A filter for monitoring and intercepting SMTP connections on qmail

BUILD_DEPENDS=	${LOCALBASE}/bin/tcprules:${PORTSDIR}/sysutils/ucspi-tcp
RUN_DEPENDS=	${LOCALBASE}/bin/tcprules:${PORTSDIR}/sysutils/ucspi-tcp

WRKSRC=		${WRKDIR}/${DISTNAME}/spamdyke

USE_QMAIL=	yes
GNU_CONFIGURE=	yes

ALL_TARGET=	spamdyke

PLIST_FILES=	bin/spamdyke

OPTIONS=	TLS "Enable TLS support" On

.include <bsd.port.pre.mk>

.if defined(WITHOUT_TLS)
CONFIGURE_ARGS+=	--disable-tls
.else
CONFIGURE_ARGS+=	--enable-tls
.endif

.if !defined(NOPORTDOCS)
PORTDOCS=	Changelog.txt FAQ.html GNUGPL.txt INSTALL.txt \
		README.html README_ip_file_format.html \
		README_rdns_directory_format.html README_rdns_file_format.html \
		UPGRADING.txt
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKDIR}/${DISTNAME}/documentation && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

post-patch:
	@${REINPLACE_CMD} -e 's#^CFLAGS :=.*#CFLAGS = ${CFLAGS}#' ${WRKSRC}/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/spamdyke ${PREFIX}/bin

.include <bsd.port.post.mk>
