# New ports collection makefile for:	ipsec-tools
# Date created:		20 dec 2004
# Whom:			vanhu
#
# $FreeBSD$

# TODO: - better list of master sites
#       - configurable --enable-xxx
#       - libipsec issue ?
#       - cleanup...
#       - SYSCONFDIR
#       - $LOCALBASE/sbin/setkey Vs /usr/sbin/setkey

PORTNAME=	ipsec-tools
PORTVERSION=	0.6
CATEGORIES=	security net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ipsec-tools

MAINTAINER=	vanhu@netasq.com
COMMENT=	KAME racoon IKE daemon, ipsec-tools version

CONFLICTS=	racoon-[0-9]*

USE_RC_SUBR=	yes
USE_OPENSSL=	yes
USE_BZIP2=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}
GNU_CONFIGURE=	yes
USE_LIBTOOL_VER=	15
INSTALLS_SHLIB=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=--enable-debug --enable-dpd --enable-natt=kernel \
		--enable-frag --enable-ipv6 --enable-shared \
		--sysconfdir=${LOCALBASE}/etc \
		--with-pkgversion=freebsd-${PORTVERSION} \

MAN3=		ipsec_set_policy.3 ipsec_strerror.3
MAN5=		racoon.conf.5
MAN8=		racoon.8 racoonctl.8 setkey.8 plainrsa-gen.8

RC_SCRIPTS_SUB=	PREFIX=${PREFIX} \
		RC_SUBR=${RC_SUBR}

PORTDOCS=	*

post-install:
	@${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/racoon.sh > ${PREFIX}/etc/rc.d/racoon.sh
	@${CHMOD} +x ${PREFIX}/etc/rc.d/racoon.sh
	@if [ -z `/sbin/sysctl -a | ${GREP} -q ipsec && ${ECHO_CMD} ipsec` ]; then \
	    ${ECHO_MSG} "WARNING: IPsec feature is disabled on this host"; \
	    ${ECHO_MSG} "         You must build the kernel if you want to run racoon on the host"; \
	fi ;
	@${MKDIR} ${EXAMPLESDIR}
	@${CP} -r ${WRKSRC}/src/racoon/samples/* ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/src/racoon/doc/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
