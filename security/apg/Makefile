# Created by: Peter Pentchev <roam@FreeBSD.org>
# $FreeBSD$

PORTNAME=	apg
PORTVERSION=	2.3.0b
PORTREVISION=	3
CATEGORIES=	security
MASTER_SITES=	http://www.adel.nursat.kz/apg/download/
MASTER_SITE_SUBDIR=	UNIX/misc

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Automated password generator

OPTIONS_DEFINE=	CRACKLIB DOCS
CRACKLIB_DESCR=	CrackLib support for password quality

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCRACKLIB}
LIB_DEPENDS=	libcrack.so:${PORTSDIR}/security/cracklib
MAKE_ARGS=	-DWITH_CRACKLIB
.endif

LICENSE=	BSD

DOCS=		APG_TIPS pronun.txt rfc0972.txt rfc1750.txt

post-extract:
	${FIND} ${WRKSRC} -type d | ${XARGS} ${CHMOD} u+wx
	${FIND} ${WRKSRC} -type f | ${XARGS} ${CHMOD} u+w

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/apg ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/apgbfm ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/apgd ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/doc/man/apg.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/man/apgbfm.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/man/apgd.8 ${STAGEDIR}${MANPREFIX}/man/man8
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/doc/,} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
