# $FreeBSD$

PORTNAME=	otpw
PORTVERSION=	1.5
CATEGORIES=	security
MASTER_SITES=	https://www.cl.cam.ac.uk/~mgk25/download/ \
		LOCAL/jkim

MAINTAINER=	jkim@FreeBSD.org
COMMENT=	One-time password login package by Markus Kuhn

LICENSE=	GPLv2+

GROUPS=		${PORTNAME}
USERS=		${PORTNAME}

MAKE_ARGS=	CC="${CC}"
USES=		gmake
LLD_UNSAFE=	yes	# lld lacks built-in search paths

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/otpw-gen ${STAGEDIR}${PREFIX}/bin
	${INSTALL_LIB} ${WRKSRC}/pam_otpw.so ${STAGEDIR}${PREFIX}/lib
	${INSTALL_MAN} ${WRKSRC}/otpw-gen.1.gz \
	    ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/pam_otpw.8.gz \
	    ${STAGEDIR}${MANPREFIX}/man/man8

.include <bsd.port.mk>
