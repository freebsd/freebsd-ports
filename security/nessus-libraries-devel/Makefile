# Ports collection makefile for:	nessus-libraries-devel
#
# $FreeBSD$
#

# Define NESSUS_CLIENT_ONLY if you only want to build this for the nessus
# client.

PORTNAME=	nessus-libraries-devel
PORTVERSION=	2.0.9
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.nessus.org/pub/nessus/nessus-${PORTVERSION}/src/ \
		ftp://ftp.gwdg.de/pub/linux/misc/nessus/nessus-${PORTVERSION}/src/ \
		http://ftp.gwdg.de/pub/linux/misc/nessus/nessus-${PORTVERSION}/src/ \
		ftp://sunsite.cnlab-switch.ch/mirror/nessus/nessus-${PORTVERSION}/src/ \
		ftp://ftp.au.nessus.org/pub/nessus/nessus-${PORTVERSION}/src/ \
		ftp://ftp.ayamura.org/pub/nessus/nessus-${PORTVERSION}/src/
DISTNAME=	nessus-libraries-${PORTVERSION}

MAINTAINER=	udo.schweigert@siemens.com
COMMENT=	Libraries for Nessus, the security scanner

DIST_SUBDIR=	nessus
WRKSRC=		${WRKDIR}/nessus-libraries

USE_BISON=	YES
USE_LIBTOOL=	YES
CONFIGURE_ARGS=	--enable-cipher --sharedstatedir=${PREFIX}/etc/nessus/com \
		--localstatedir=${PREFIX}/etc/nessus/var
.if defined(WITH_NESSUS_BPF_SHARE)
CONFIGURE_ARGS+=	--enable-bpf-sharing
.endif

INSTALLS_SHLIB=	YES

MAN1=		nessus-config.1

.if ! defined(NESSUS_CLIENT_ONLY)
pre-configure:
	@if [ ! -c /dev/bpf1 ]; then \
	    ${ECHO} "********************************************************";\
	    ${ECHO} "*                   W a r n i n g                      *";\
	    ${ECHO} "*                                                      *";\
	    ${ECHO} "* Nessus needs Berkeley Packet Filter (bpf).           *";\
	    ${ECHO} "* To use nessus, your kernel must be rebuilt with bpf, *";\
	    ${ECHO} "* and make bpf devices on /dev directory.              *";\
	    ${ECHO} "*                                                      *";\
	    ${ECHO} "* Be sure to build as many bpf devices as you need.    *";\
	    ${ECHO} "* For more info on this read files/README.BPF          *";\
	    ${ECHO} "********************************************************";\
	    ${FALSE}; \
	fi
.if ! defined(WITH_NESSUS_BPF_SHARE)
	@if [ ! -c /dev/bpf40 ]; then \
	    ${ECHO} "********************************************************";\
	    ${ECHO} "*                   W a r n i n g                      *";\
	    ${ECHO} "*                                                      *";\
	    ${ECHO} "* Nessus needs many bpf devices. If you can't rebuild  *";\
	    ${ECHO} "* your kernel with more than 40 bpf devices (as        *";\
	    ${ECHO} "* described in files/README.BPF) then build this port  *";\
	    ${ECHO} "* with \"make -DWITH_NESSUS_BPF_SHARE\"                  *";\
	    ${ECHO} "*                                                      *";\
	    ${ECHO} "********************************************************";\
	    ${FALSE}; \
	fi
.endif
.endif

.include <bsd.port.mk>
