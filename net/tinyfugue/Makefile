# New ports collection makefile for:	tinyfugue
# Date created:		4 January 1997
# Whom:			mike@binghamton.edu
#
# $FreeBSD$
#

PORTNAME=	tf
PORTVERSION=	4.0s1
CATEGORIES=	net games
MASTER_SITES=	ftp://tf.tcp.com/pub/tinyfugue/ \
		ftp://laurel.actlab.utexas.edu/pub/tinyfugue/ \
		ftp://ftp.ci.uminho.pt/pub/mirrors/tinyfugue/
DISTNAME=	tf-40s1

MAINTAINER=	fjoe@FreeBSD.org

.if defined(PARALLEL_PACKAGE_BUILD)
BROKEN=		tries to cd to directory that do not exist yet
.endif

PLIST_SUB=	DISTNAME=${DISTNAME}

MAKEFILE=	${WRKSRC}/unix/Makefile
MAKE_ENV=	TFVER=${DISTNAME:S/^tf-//}

MAN1=		tf.1

.include <bsd.port.pre.mk>

.if defined(WITH_MCCP)
EXTRA_PATCHES=	${FILESDIR}/mccp-patch
PKGNAMESUFFIX=	-mccp

post-extract:
	@${CP} ${FILESDIR}/mccp.[ch] ${WRKSRC}/src
.else
pre-extract:
	@${ECHO_MSG}
	@${ECHO_MSG} "You can enable MCCP v1/v2 support by defining WITH_MCCP"
	@${ECHO_MSG}
.endif

.include <bsd.port.post.mk>
