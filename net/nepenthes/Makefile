# Ports collection makefile for:	nepenthes
# Date created:				1 Dec 2005
# Whom:					ryo
#
# $FreeBSD$
#

PORTNAME=	nepenthes
PORTVERSION=	0.2.2
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/Nepenthes%20development/${PORTVERSION}

MAINTAINER=	systemoperator@gmail.com
COMMENT=	Determine the malware activity on a network

LIB_DEPENDS=	curl.5:${PORTSDIR}/ftp/curl \
		magic.1:${PORTSDIR}/sysutils/file \
		pcre.0:${PORTSDIR}/devel/pcre \
		adns.1:${PORTSDIR}/dns/adns

.if defined(WITH_PRELUDE)
LIB_DEPENDS+=		prelude.19:${PORTSDIR}/security/libprelude
CONFIGURE_ARGS+=	--enable-prelude
.endif

.if defined(WITH_DEBUG_LOGGING)
CONFIGURE_ARGS+=	--enable-debug-logging
.endif

USE_PERL5=	yes
GNU_CONFIGURE=	yes

DOCS=	README README.VFS logo-shaded.svg
MAN8=	nepenthes.8

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.in -print0 | ${XARGS} -0 \
	${REINPLACE_CMD} -e 's,-Werror,,'

.include <bsd.port.mk>
