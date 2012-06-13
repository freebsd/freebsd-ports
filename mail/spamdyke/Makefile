# New ports collection makefile for:	spamdyke
# Date created:		11 January 2007
# Whom:			Peter Kieser <peter@kieser.ca>
#
# $FreeBSD$
#

PORTNAME=	spamdyke
PORTVERSION=	4.3.1
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

OPTIONS_DEFINE=	TLS DEBUG DEBUG_EXCESSIVE DOCS
OPTIONS_DEFAULT=	TLS
TLS_DESC=	Enable TLS support
DEBUG_DESC=	Enable debugging output

.include <bsd.port.pre.mk>

.if ${CC:T:Mclang} == "clang"
IGNORE=	uses nested functions, not supported by clang
.endif

.if ${PORT_OPTIONS:MTLS}
CONFIGURE_ARGS+=	--enable-tls
.else
CONFIGURE_ARGS+=	--disable-tls
.endif

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--with-debug-output
.else
CONFIGURE_ARGS+=	--without-debug-output
.endif

.if ${PORT_OPTIONS:MDEBUG_EXCESSIVE}
CONFIGURE_ARGS+=	--with-excessive-output
.else
CONFIGURE_ARGS+=	--without-excessive-output
.endif

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	Changelog.txt FAQ.html GNUGPL.txt INSTALL.txt \
		README.html README_ip_file_format.html \
		README_rdns_directory_format.html README_rdns_file_format.html \
		UPGRADING.txt UPGRADING_version_3_to_version_4.txt
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
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
