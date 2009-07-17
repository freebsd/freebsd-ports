# New ports collection makefile for:	junkbuster
# Date created:		2 May 1998
# Whom:			Ian Struble <ian@broken.net>
#
# $FreeBSD$

PORTNAME=	junkbuster
PORTVERSION=	2.0.2
PORTREVISION=	6
CATEGORIES=	www
MASTER_SITES=	http://f2.org/download/ \
		http://www.junkbusters.com/ht/en/
DISTNAME=	ijb-zlib-10
EXTRACT_SUFX=	.tgz

MAINTAINER=	edwin@mavetju.org
COMMENT=	An HTTP proxy server that eliminates ads

ALL_TARGET=	# yes, an empty target.
JDIR=		${PREFIX}/etc/junkbuster
MAN1=		junkbuster.1
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
	@${INSTALL_PROGRAM} ${WRKSRC}/junkbuster ${PREFIX}/sbin/junkbuster
	@${MKDIR} -m 755 ${JDIR}
	@${INSTALL_DATA} ${WRKSRC}/junkbstr.ini ${JDIR}/configfile.sample
	@${INSTALL_DATA} ${WRKSRC}/sblock.ini ${JDIR}/blockfile.sample
	@${INSTALL_DATA} ${WRKSRC}/saclfile.ini ${JDIR}/aclfile.sample
	@${INSTALL_DATA} ${WRKSRC}/scookie.ini ${JDIR}/cookiefile.sample
	@${INSTALL_DATA} ${WRKSRC}/sforward.ini ${JDIR}/forwardfile.sample
	@${INSTALL_DATA} ${WRKSRC}/strust.ini ${JDIR}/trustfile.sample
	@${INSTALL_MAN} ${WRKSRC}/junkbuster.1 ${PREFIX}/man/man1/

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
