# New ports collection makefile for:	py-pcap
# Date created:		24 Nov 2001
# Whom:			Hye-Shik Chang
#
# $FreeBSD$
#

PORTNAME=	pcap
PORTVERSION=	0.5
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://people.freebsd.org/~perky/distfiles/:local
MASTER_SITE_SUBDIR=	pylibpcap
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	pylibpcap-${PORTVERSION}.tar.gz \
		pylibpcap-doc.i.1.4:local
EXTRACT_ONLY=	pylibpcap-${PORTVERSION}.tar.gz

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Python interface to LBL Packet Capture library (libpcap)

BUILD_DEPENDS=	swig:${PORTSDIR}/devel/swig13

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_PYTHON_PREFIX=	yes
PYDISTUTILS_PKGNAME=	pylibpcap
WRKSRC=		${WRKDIR}/pylibpcap-${PORTVERSION}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 460001 || \
	( ${OSVERSION} >= 500000 && ${OSVERSION} < 500038 )
IGNORE=		"needs libpcap 0.7 or higher"
.endif

post-extract:
	${INSTALL_DATA} ${DISTDIR}/pylibpcap-doc.i.1.4 ${WRKSRC}/doc.i

.include <bsd.port.post.mk>
