# New ports collection makefile for:	healthd
# Date created:		15 November 1999
# Whom:			jim@thehousleys.net
#
# $FreeBSD$
#

PORTNAME=	healthd
PORTVERSION=	0.7.9
PORTREVISION=	1
CATEGORIES=	sysutils ipv6
MASTER_SITES=	http://healthd.thehousleys.net/ \
		http://healthd1.thehousleys.net/

MAINTAINER=	jeh@FreeBSD.org
COMMENT=	A daemon to monitor vital motherboard parameters

ONLY_FOR_ARCHS=	i386 amd64

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--exec-prefix=${PREFIX}
#
# To allow reading the doWarn and doFail scripts remotely uncomment
# the following line.  Enabling the following option might provide
# information about the configuration of you system.
#CONFIGURE_ARGS+= --enable-full-config

MAN8=		healthd.8 healthdc.8
INSTALL_TARGET=	install-all

HDDOCDIR=	${PREFIX}/share/doc/healthd

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400014 || defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=	--disable-ipv6
.endif

USE_RC_SUBR=	yes

post-install:
	@${REINPLACE_CMD} -e 's|/usr/local/etc/rc.subr|${RC_SUBR}|' ${WRKSRC}/healthd.sh
	${INSTALL_SCRIPT} -m 751 ${WRKSRC}/healthd.sh ${PREFIX}/etc/rc.d/healthd.sh
	@if [ ! -f ${PREFIX}/etc/healthd.conf ]; then \
		${ECHO} "Installing ${PREFIX}/etc/healthd.conf configuration file."; \
		${ECHO} "It is recommended you edit this file to match your system"; \
		${ECHO} "before running the program."; \
		${CP} ${PREFIX}/etc/healthd.conf.sample ${PREFIX}/etc/healthd.conf; \
	fi
.if !defined(NOPORTDOCS)
	@if ! [ -d ${HDDOCDIR} ]; then ${MKDIR} ${HDDOCDIR}; fi
	${INSTALL_DATA} ${WRKSRC}/README ${HDDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/PROTOCOL ${HDDOCDIR}
.endif

pre-everything::
.ifndef (WITHOUT_IPV6)
	@${ECHO_MSG} "WITHOUT_IPV6=yes          builds without IPv6 support"
.endif
.include <bsd.port.post.mk>
