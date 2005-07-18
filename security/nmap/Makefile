# Ports collection makefile for:  nmap
# Date created:			  Tue Aug 04, 1998
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME?=	nmap
PORTVERSION=	${DISTVERSION:L:C/([a-z])[a-z]+/\1/g:C/[^a-z0-9+]+/./g}
CATEGORIES=	security ipv6
MASTER_SITES=	http://download.insecure.org/nmap/dist/ \
		http://www.mirrors.wiretapped.net/security/network-mapping/nmap/ \
		http://ftp.iasi.roedu.net/mirrors/download.insecure.org/nmap/dist/ \
		http://shadow.cc.columbia.edu/pub/software/nmap/
DISTNAME=	nmap-${DISTVERSION}	# needed for security/nmapfe

MAINTAINER=	ports@FreeBSD.org
COMMENT?=	Port scanning utility for large networks

DISTVERSION=	3.81

USE_BZIP2=	yes
USE_REINPLACE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-localdirs

CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

.ifndef BUILD_NMAPFE

MAN1=		nmap.1
MANLANG=	"" de.ISO8859-1 es.ISO8859-1 fr.ISO8859-1 it.ISO8859-15 \
		lt.ISO8859-13 pt.ISO8859-1 ru.KOI8-R

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

post-configure:
	@${REINPLACE_CMD} -e "s|^DESTDIR *=|& ${DESTDIR}|" ${WRKSRC}/Makefile

post-install:
	@for lang in de.ISO8859-1=german es.ISO8859-1=spanish fr.ISO8859-1=french it.ISO8859-15=italian \
		lt.ISO8859-13=lithuanian pt.ISO8859-1=portuguese ru.KOI8-R=russian; do \
		llang="`expr $${lang} : '\([^=]*\)'`"; \
		elang="`expr $${lang} : '.*=\([^=]*\)'`"; \
		${MKDIR} ${DESTDIR}${MAN1PREFIX}/man/$${llang}/man1; \
		${INSTALL_MAN} ${WRKSRC}/docs/nmap_$${elang}.1 \
			${DESTDIR}${MAN1PREFIX}/man/$${llang}/man1/nmap.1; \
	done
.ifndef NOPORTDOCS
	@${MKDIR} ${DESTDIR}${DOCSDIR}
	@for doc in CHANGELOG HACKING docs/nmap.dtd; do \
		${INSTALL_DATA} ${WRKSRC}/$${doc} ${DESTDIR}${DOCSDIR}; \
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

.endif

.include <bsd.port.mk>
