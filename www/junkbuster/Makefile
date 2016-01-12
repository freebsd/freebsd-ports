# Created by: Ian Struble <ian@broken.net>
# $FreeBSD$

PORTNAME=	junkbuster
PORTVERSION=	2.0.2
PORTREVISION=	7
CATEGORIES=	www
MASTER_SITES=	http://f2.org/download/
DISTNAME=	ijb-zlib-11

MAINTAINER=	ports@FreeBSD.org
COMMENT=	HTTP proxy server that eliminates ads

LICENSE=	GPLv2+

USES=		tar:tgz
ALL_TARGET=	# yes, an empty target.
JDIR=		${PREFIX}/etc/junkbuster
SUB_FILES=	junkbuster pkg-message
USE_RC_SUBR=	${PORTNAME}
PKGMESSAGE=	${WRKDIR}/pkg-message

GNUREGEXP=	's:gnu_regex.h:gnu/regex.h:'

post-patch:
.for f in junkbstr.ini saclfile.ini sblock.ini scookie.ini sforward.ini strust.ini win32.h
	@${REINPLACE_CMD} -e "s:`/usr/bin/printf '\r'`::" ${WRKSRC}/${f}
.endfor
.for f in acl.c bind.c conn.c encode.c filters.c gnu_regex.c jcc.c loaders.c parsers.c socks4.c ssplit.c win32.c
	@${REINPLACE_CMD} -e ${GNUREGEXP} ${WRKSRC}/${f}
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/junkbuster ${STAGEDIR}${PREFIX}/sbin/junkbuster
	@${MKDIR} -m 755 ${STAGEDIR}${JDIR}
	${INSTALL_DATA} ${WRKSRC}/junkbstr.ini ${STAGEDIR}${JDIR}/configfile.sample
	${INSTALL_DATA} ${WRKSRC}/sblock.ini ${STAGEDIR}${JDIR}/blockfile.sample
	${INSTALL_DATA} ${WRKSRC}/saclfile.ini ${STAGEDIR}${JDIR}/aclfile.sample
	${INSTALL_DATA} ${WRKSRC}/scookie.ini ${STAGEDIR}${JDIR}/cookiefile.sample
	${INSTALL_DATA} ${WRKSRC}/sforward.ini ${STAGEDIR}${JDIR}/forwardfile.sample
	${INSTALL_DATA} ${WRKSRC}/strust.ini ${STAGEDIR}${JDIR}/trustfile.sample
	${INSTALL_MAN} ${WRKSRC}/junkbuster.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
