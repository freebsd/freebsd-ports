# New ports collection makefile for:	tinyfugue
# Date created:		4 January 1997
# Whom:			mike@binghamton.edu
#
# $FreeBSD$
#

PORTNAME=	tf
PORTVERSION=	4.0s1
CATEGORIES=	net games
MASTER_SITES=	http://ftp.tcp.com/pub/mud/Clients/tinyfugue/ \
		ftp://ftp.minet.uni-jena.de/pub/tf/
.if !defined(WITHOUT_MCCP)
PKGNAMESUFFIX=	-mccp
.endif
DISTNAME=	tf-40s1

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	A popular programmable MUD client, with macro support and more

PLIST_SUB=	DISTNAME=${DISTNAME}

MAKEFILE=	${WRKSRC}/unix/Makefile
MAKE_ENV=	TFVER=${DISTNAME:S/^tf-//} CC="${CC}" CFLAGS="${CFLAGS}"

MAN1=		tf.1

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_MCCP)
EXTRA_PATCHES=	${FILESDIR}/mccp-patch

post-extract:
	@${CP} ${FILESDIR}/mccp.[ch] ${WRKSRC}/src
.else
pre-extract:
	@${ECHO_MSG}
	@${ECHO_MSG} "You can disable MCCP v1/v2 support by defining WITHOUT_MCCP"
	@${ECHO_MSG}
.endif

.include <bsd.port.post.mk>
