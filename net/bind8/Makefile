# New ports collection makefile for:	bind
# Date created:		18 July 1997
# Whom:			jseger@scds.com
#
# $FreeBSD$
#

# I stay very aware of developments regarding BIND. I frequently delay updating
# this port from a known-stable version due to concerns about stability of a
# newer version. If you are interested in using the most recent ISC release
# you can generally build it cleanly from the source. - Doug

PORTNAME=	bind
PORTVERSION=	8.3.3
PORTREVISION=	1
CATEGORIES?=	net
MASTER_SITES=	${MASTER_SITE_ISC}
MASTER_SITE_SUBDIR=	bind/src/${PORTVERSION}

DISTFILES=	bind-src.tar.gz bind-doc.tar.gz
DIST_SUBDIR=	bind-${PORTVERSION}

MAINTAINER=	DougB@FreeBSD.org

.if defined(PORT_REPLACES_BASE_BIND8)
PKGNAMESUFFIX=	-base
PREFIX=		/usr
BIND_DESTETC=	/etc/namedb
.else
BIND_DESTETC=	${PREFIX}/etc
.endif

WRKSRC=		${WRKDIR}/src
MAKE_ENV+=	MANPREFIX=${MANPREFIX}

MAN1=		dig.1 dnskeygen.1 dnsquery.1 host.1
MAN3=		getaddrinfo.3 gethostbyname.3 getipnodebyname.3 getnetent.3 \
		getnameinfo.3 inet_cidr.3 hesiod.3 resolver.3 tsig.3
MAN5=		irs.conf.5 named.conf.5 resolver.5
MAN7=		hostname.7 mailaddr.7
MAN8=		named-bootconf.8 named-xfer.8 named.8 ndc.8 nslookup.8 \
		nsupdate.8

PATCH_ARGS=	-s -d ${WRKDIR}
PATCH_DIST_ARGS=	-s -d ${WRKDIR}

post-patch:
	@${SED} -e "s#\'DESTETC=.*#'DESTETC=${BIND_DESTETC}'#" \
		-e "s#-O2 -g#${CFLAGS}#" \
		${WRKSRC}/port/freebsd/Makefile.set > \
		${WRKSRC}/port/freebsd/Makefile.set.sed
	@${MV} ${WRKSRC}/port/freebsd/Makefile.set.sed \
		${WRKSRC}/port/freebsd/Makefile.set
.for file in named.conf.5 named.8
	@${SED} -e "s#/etc/named.conf#${BIND_DESTETC}/named.conf#g" \
		${WRKDIR}/doc/man/${file} > ${WRKDIR}/doc/man/${file}.sed
	@${MV} ${WRKDIR}/doc/man/${file}.sed ${WRKDIR}/doc/man/${file}
.endfor

post-install:
	cd ${WRKDIR}/doc/man && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} \
		${MAKEFILE} clean all ${INSTALL_TARGET}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/html
	${INSTALL_DATA} ${WRKDIR}/doc/html/*.html ${DOCSDIR}/html
	${CP} -Rp ${WRKDIR}/src/conf ${DOCSDIR}
.for file in CHANGES DNSSEC LICENSE LICENSE_RSA README SUPPORT TODO
	${INSTALL_DATA} ${WRKDIR}/src/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
