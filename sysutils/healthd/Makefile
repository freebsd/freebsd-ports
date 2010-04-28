# New ports collection makefile for:	healthd
# Date created:		15 November 1999
# Whom:			jim@thehousleys.net
#
# $FreeBSD$
#

PORTNAME=	healthd
PORTVERSION=	0.7.9
PORTREVISION=	2
CATEGORIES=	sysutils ipv6
MASTER_SITES=	http://healthd.thehousleys.net/ \
		http://healthd1.thehousleys.net/

MAINTAINER=	apache@FreeBSD.org
COMMENT=	A daemon to monitor vital motherboard parameters

OPTIONS=	IPV6		"IPv6 support"			off \
			FULL_CONFIG "Full Config support" 	off

ONLY_FOR_ARCHS=	i386 amd64
USE_RC_SUBR=	${PORTNAME}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--exec-prefix=${PREFIX}

MAN8=		healthd.8 healthdc.8
INSTALL_TARGET=	install-all

.if defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if defined(WITH_FULL_CONFIG)
CONFIGURE_ARGS+=	--enable-full-config
.endif

post-install:
	@if [ ! -f ${PREFIX}/etc/healthd.conf ]; then \
		${ECHO} "Installing ${PREFIX}/etc/healthd.conf configuration file."; \
		${ECHO} "It is recommended you edit this file to match your system"; \
		${ECHO} "before running the program."; \
		${CP} ${PREFIX}/etc/healthd.conf.sample ${PREFIX}/etc/healthd.conf; \
	fi
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/PROTOCOL ${DOCSDIR}/
.endif

.include <bsd.port.mk>
