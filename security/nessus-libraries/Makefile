# Created by: Anders Nordby <anders@fix.no>
# $FreeBSD$

# Define NESSUS_CLIENT_ONLY if you only want to build this for the nessus
# client.

PORTNAME=	nessus-libraries
PORTVERSION=	2.2.9
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.nessus.org/pub/nessus/nessus-${PORTVERSION}/src/ \
		ftp://ftp.gwdg.de/pub/linux/misc/nessus/nessus-${PORTVERSION}/src/ \
		http://ftp.gwdg.de/pub/linux/misc/nessus/nessus-${PORTVERSION}/src/ \
		ftp://sunsite.cnlab-switch.ch/mirror/nessus/nessus-${PORTVERSION}/src/ \
		ftp://ftp.ayamura.org/pub/nessus/nessus-${PORTVERSION}/src/
DIST_SUBDIR=	nessus

MAINTAINER=	udo.schweigert@siemens.com
COMMENT=	Libraries for Nessus, the security scanner

LICENSE=	LGPL20

WRKSRC=		${WRKDIR}/nessus-libraries
USES=		bison
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--enable-cipher
.if defined(WITH_NESSUS_BPF_SHARE)
CONFIGURE_ARGS+=	--enable-bpf-sharing
.endif
USE_LDCONFIG=	YES

.if ! defined(NESSUS_CLIENT_ONLY)
pre-everything::
	@if [ ! -c /dev/bpf ]; then \
	    ${ECHO} "********************************************************";\
	    ${ECHO} "*                   W a r n i n g                      *";\
	    ${ECHO} "*                                                      *";\
	    ${ECHO} "* Nessus needs Berkeley Packet Filter (bpf).           *";\
	    ${ECHO} "* To use nessus, your kernel must be rebuilt with bpf, *";\
	    ${ECHO} "* and make bpf devices on /dev directory.              *";\
	    ${ECHO} "*                                                      *";\
	    ${ECHO} "* For more info on this read files/README.BPF          *";\
	    ${ECHO} "********************************************************";\
	    ${FALSE}; \
	fi
.endif

.include <bsd.port.mk>
