# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/net/libproxy-perl/Makefile,v 1.1 2011/01/12 13:10:53 kwm Exp $

PORTREVISION=	1
CATEGORIES=	net lang
PKGNAMESUFFIX=	-perl

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Perl binding for libproxy

LIB_DEPENDS=	libproxy.so:${PORTSDIR}/net/libproxy

MASTERDIR=	${.CURDIR}/../libproxy
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist
USES=		perl5

LIBPROXY_SLAVE=	perl

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Net/Libproxy ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/Net
	${INSTALL_LIB} ${WRKSRC}/perl/blib/arch/auto/Net/Libproxy.so \
		${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Net/Libproxy
	${INSTALL_DATA} ${WRKSRC}/perl/blib/lib/Libproxy.pm \
		${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/Net

.include "${MASTERDIR}/Makefile"
