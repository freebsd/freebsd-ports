# Ports collection makefile for:  nmap
# Date created:			  Tue Aug 04, 1998
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME?=	nmap
PORTVERSION=	3.46
CATEGORIES=	security ipv6
MASTER_SITES=	http://download.insecure.org/nmap/dist/
DISTNAME=	nmap-${PORTVERSION}

MAINTAINER=	eikemeier@fillmore-labs.com
COMMENT?=	Port scanning utility for large networks

USE_BZIP2=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-localdirs

CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

.ifndef BUILD_NMAPFE

MAN1=		nmap.1

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre

CONFIGURE_ARGS+=	--with-libpcre=${LOCALBASE}

.ifndef WITHOUT_SSL
USE_OPENSSL=	yes
CONFIGURE_ARGS+=	--with-openssl=${OPENSSLBASE}
.else
CONFIGURE_ARGS+=	--without-openssl
.endif

CONFIGURE_ARGS+=	--without-nmapfe

ALL_TARGET=	nmap
INSTALL_TARGET=	install-nmap

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/nmap
.ifndef NOPORTDOCS
	@${MKDIR} ${DOCSDIR}
	@for doc in CHANGELOG HACKING docs/nmap.dtd; do \
		${INSTALL_DATA} ${WRKSRC}/$${doc} ${DOCSDIR}; \
	done
.endif

.else

RUN_DEPENDS=	nmap:${PORTSDIR}/security/nmap

DESCR=		${PKGDIR}/pkg-descr.fe
PLIST=		${PKGDIR}/pkg-plist.fe
PLIST_SUB=	REALPREFIX=${PREFIX}

MAN1=		nmapfe.1
MLINKS=		nmapfe.1 xnmap.1

USE_GNOME=	gtk12

CONFIGURE_ARGS+=--without-openssl

CONFIGURE_ARGS+=--with-nmapfe

ALL_TARGET=	nbase/libnbase.a nmapfe/nmapfe
INSTALL_TARGET=	install-nmapfe

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/nmapfe

.endif

.include <bsd.port.mk>
