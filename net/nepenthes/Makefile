# Ports collection makefile for:	nepenthes
# Date created:				1 Dec 2005
# Whom:					ryo
#
# $FreeBSD$
#

PORTNAME=	nepenthes
PORTVERSION=	0.1.7
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	nepenthes

MAINTAINER=	ryo@aquahill.net
COMMENT=	Determine the malware activity on a network

LIB_DEPENDS=	curl.3:${PORTSDIR}/ftp/curl \
		magic.1:${PORTSDIR}/sysutils/file \
		pcre.0:${PORTSDIR}/devel/pcre \
		adns.1:${PORTSDIR}/dns/adns

USE_PERL5=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN8=		nepenthes.8
DOCS=		README README.VFS logo-shaded.svg

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		Does not compile
.endif

.if ${ARCH} != "i386"
BROKEN=		Does not compile on !i386
.endif

.include <bsd.port.post.mk>
