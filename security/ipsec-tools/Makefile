# New ports collection makefile for:	ipsec-tools
# Date created:		20 dec 2004
# Whom:			vanhu
#
# $FreeBSD$

# TODO: - configurable --enable-xxx
#       - libipsec issue ?
#       - cleanup...
#       - SYSCONFDIR
#       - $LOCALBASE/sbin/setkey Vs /usr/sbin/setkey

PORTNAME=	ipsec-tools
PORTVERSION=	0.6.5
PORTREVISION=	1
CATEGORIES=	security net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ipsec-tools

MAINTAINER=	vanhu@netasq.com
COMMENT=	KAME racoon IKE daemon, ipsec-tools version

CONFLICTS=	racoon-[0-9]*

USE_RC_SUBR=	racoon.sh
USE_OPENSSL=	yes
USE_BZIP2=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
LDFLAGS=	-L${LOCALBASE}/lib
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--enable-debug --enable-dpd --enable-natt=kernel \
		--enable-frag --enable-ipv6 --enable-shared \
		--sysconfdir=${PREFIX}/etc/racoon \
		--with-pkgversion=freebsd-${PORTVERSION}

MAN3=		ipsec_set_policy.3 ipsec_strerror.3
MAN5=		racoon.conf.5
MAN8=		racoon.8 racoonctl.8 setkey.8 plainrsa-gen.8

PORTDOCS=	*

post-install:
	@if [ -z `/sbin/sysctl -a | ${GREP} -q ipsec && ${ECHO_CMD} ipsec` ]; then \
	    ${ECHO_MSG} "WARNING: IPsec feature is disabled on this host"; \
	    ${ECHO_MSG} "         You must build the kernel if you want to run racoon on the host"; \
	fi ;
	@${MKDIR} ${EXAMPLESDIR}
	@${RM} -f ${WRKSRC}/src/racoon/samples/*.in
	@${CP} -r ${WRKSRC}/src/racoon/samples/* ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/src/racoon/doc/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
