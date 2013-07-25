# Created by: Colin Percival
# $FreeBSD$

PORTNAME=	tarsnap
PORTVERSION=	1.0.35
CATEGORIES=	sysutils
MASTER_SITES=	http://www.tarsnap.com/download-http/
DISTNAME=	${PORTNAME}-autoconf-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	cperciva@tarsnap.com
COMMENT=	Online encrypted backup service (client)

RESTRICTED=	license restricts redistribution of source and binaries

GNU_CONFIGURE=	yes
USES=		gmake

MAN1=		tarsnap.1 tarsnap-keygen.1 tarsnap-keymgmt.1	\
		tarsnap-keyregen.1 tarsnap-recrypt.1
MAN5=		tarsnap.conf.5

OPTIONS_DEFINE=	SSE2
SSE2_DESC=	Use SSE2-optimized code

SSE2_CONFIGURE_ENABLE=	sse2
SSE2_CFLAGS=	-msse2

post-install:
	@if [ ! -f ${PREFIX}/etc/tarsnap.conf ]; then \
	    ${CP} -p ${PREFIX}/etc/tarsnap.conf.sample ${PREFIX}/etc/tarsnap.conf ; \
	fi
	@${CAT} ${PKGDIR}/pkg-message

.include <bsd.port.mk>
