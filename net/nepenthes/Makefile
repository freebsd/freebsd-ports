# Created by: ryo
# $FreeBSD$

PORTNAME=	nepenthes
PORTVERSION=	0.2.2
PORTREVISION=	8
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/Nepenthes%20development/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Determine the malware activity on a network

LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl \
		libmagic.so:${PORTSDIR}/sysutils/file \
		libpcre.so:${PORTSDIR}/devel/pcre \
		libadns.so:${PORTSDIR}/dns/adns

.if defined(WITH_PRELUDE)
LIB_DEPENDS+=		libprelude.so:${PORTSDIR}/security/libprelude
CONFIGURE_ARGS+=	--enable-prelude
.endif

.if defined(WITH_DEBUG_LOGGING)
CONFIGURE_ARGS+=	--enable-debug-logging
.endif

USES=		perl5
GNU_CONFIGURE=	yes

DOCS=	README README.VFS logo-shaded.svg
MAN8=	nepenthes.8

NO_STAGE=	yes
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
