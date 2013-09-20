# Created by: Peter Pentchev <roam@FreeBSD.org>
# $FreeBSD$

PORTNAME=	apg
PORTVERSION=	2.3.0b
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://www.adel.nursat.kz/apg/download/
MASTER_SITE_SUBDIR=	UNIX/misc

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Automated password generator

OPTIONS_DEFINE=	CRACKLIB
CRACKLIB_DESCR=	CrackLib support for password quality

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCRACKLIB}
LIB_DEPENDS=	crack:${PORTSDIR}/security/cracklib
MAKE_ARGS=	-DWITH_CRACKLIB
.endif

LICENSE=	BSD

MAN1=		apg.1 apgbfm.1
MAN8=		apgd.8
DOCS=		APG_TIPS pronun.txt rfc0972.txt rfc1750.txt

post-extract:
	${FIND} ${WRKSRC} -type d | ${XARGS} ${CHMOD} u+wx
	${FIND} ${WRKSRC} -type f | ${XARGS} ${CHMOD} u+w

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/apg ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/apgbfm ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/apgd ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/doc/man/apg.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/man/apgbfm.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/man/apgd.8 ${MANPREFIX}/man/man8
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/doc/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
