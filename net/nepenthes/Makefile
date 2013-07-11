# Created by: ryo
# $FreeBSD$

PORTNAME=	nepenthes
PORTVERSION=	0.2.2
PORTREVISION=	7
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/Nepenthes%20development/${PORTVERSION}

MAINTAINER=	systemoperator@gmail.com
COMMENT=	Determine the malware activity on a network

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl \
		magic.1:${PORTSDIR}/sysutils/file \
		pcre.3:${PORTSDIR}/devel/pcre \
		adns.1:${PORTSDIR}/dns/adns

.if defined(WITH_PRELUDE)
LIB_DEPENDS+=		prelude:${PORTSDIR}/security/libprelude
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
	@${REINPLACE_CMD} -e '/<curl\/types.h>/d' \
		${WRKSRC}/modules/download-curl/download-curl.hpp \
		${WRKSRC}/modules/submit-http/HTTPSession.hpp \
		${WRKSRC}/modules/submit-http/HTTPSession.cpp \
		${WRKSRC}/modules/submit-http/submit-http.hpp \
		${WRKSRC}/modules/submit-mwserv/TransferSession.hpp \
		${WRKSRC}/modules/submit-mwserv/submit-mwserv.hpp \
		${WRKSRC}/modules/submit-norman/submit-norman.hpp

.include <bsd.port.mk>
