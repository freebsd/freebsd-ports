# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/net/libproxy-perl/Makefile,v 1.1 2011/01/12 13:10:53 kwm Exp $

PORTREVISION=	0
CATEGORIES=	net lang
PKGNAMESUFFIX=	-perl

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Perl binding for libproxy

LIB_DEPENDS=	proxy.1:${PORTSDIR}/net/libproxy

MASTERDIR=	${.CURDIR}/../libproxy
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist
USES=		perl5

LIBPROXY_SLAVE=	perl

NO_STAGE=	yes
do-install:
	${MKDIR} ${SITE_PERL}/mach/auto/Net/Libproxy ${SITE_PERL}/mach/Net
	${INSTALL_LIB} ${WRKSRC}/perl/blib/arch/auto/Net/Libproxy.so \
		${SITE_PERL}/mach/auto/Net/Libproxy/
	${INSTALL_DATA} ${WRKSRC}/perl/blib/lib/Libproxy.pm \
		${SITE_PERL}/mach/Net/

.include "${MASTERDIR}/Makefile"
