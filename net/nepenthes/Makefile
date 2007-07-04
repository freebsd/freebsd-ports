# Ports collection makefile for:	nepenthes
# Date created:				1 Dec 2005
# Whom:					ryo
#
# $FreeBSD$
#

PORTNAME=	nepenthes
PORTVERSION=	0.2.0
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	nepenthes

MAINTAINER=	systemoperator@gmail.com
COMMENT=	Determine the malware activity on a network

LIB_DEPENDS=	curl.4:${PORTSDIR}/ftp/curl \
		magic.1:${PORTSDIR}/sysutils/file \
		pcre.0:${PORTSDIR}/devel/pcre \
		adns.1:${PORTSDIR}/dns/adns

.if defined(WITH_PRELUDE)
LIB_DEPENDS+=		prelude.12:${PORTSDIR}/security/libprelude
CONFIGURE_ARGS+=	--enable-prelude
EXTRA_PATCHES=		${FILESDIR}/prelude_modules_log-prelude_Makefile.in.patch
.endif

.if defined(WITH_DEBUG_LOGGING)
CONFIGURE_ARGS+=	--enable-debug-logging
.endif

USE_PERL5=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/man --infodir=${PREFIX}/info

DOCS=	README README.VFS logo-shaded.svg
MAN8=	nepenthes.8

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.in -print0 | ${XARGS} -0 \
	${REINPLACE_CMD} -e 's,-Werror,,'

.include <bsd.port.mk>
